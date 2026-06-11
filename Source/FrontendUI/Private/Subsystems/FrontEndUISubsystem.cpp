// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Subsystems/FrontEndUISubsystem.h"
#include "FrontEndDebugHelper.h"
#include "Engine/AssetManager.h"
#include "Widgets/Widget_PrimaryLayout.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "Widgets/Widget_ActivatableBase.h"


UFrontEndUISubsystem* UFrontEndUISubsystem::Get(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject,EGetWorldErrorMode::Assert);

		return UGameInstance::GetSubsystem<UFrontEndUISubsystem>(World->GetGameInstance());
	}

	return nullptr;
}

bool UFrontEndUISubsystem::ShouldCreateSubsystem(UObject* Outer) const
{	
	if (!CastChecked<UGameInstance>(Outer)->IsDedicatedServerInstance())
	{	
		TArray<UClass*> FoundClasses;
		GetDerivedClasses(GetClass(),FoundClasses);

		return FoundClasses.IsEmpty();
	}

	return false;
}

void UFrontEndUISubsystem::RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget)
{	
	check(InCreatedWidget);

	CreatedPrimaryLayout = InCreatedWidget;

	Debug::Print(TEXT("Primary layout widget stored"));
}


void UFrontEndUISubsystem::PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag, TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass,TFunction<void(EAsyncPushWidgetState,UWidget_ActivatableBase*)> AsyncPushStateCallback)
{
	check(!InSoftWidgetClass.IsNull());

	UAssetManager::Get().GetStreamableManager().RequestAsyncLoad(
		InSoftWidgetClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateLambda(
			[InSoftWidgetClass,this,InWidgetStackTag,AsyncPushStateCallback]()
			{
				UClass* LoadedWidgetClass = InSoftWidgetClass.Get();
				
				check(LoadedWidgetClass && CreatedPrimaryLayout);

				UCommonActivatableWidgetContainerBase* FoundWidgetStack = CreatedPrimaryLayout->FindWidgetStackByTag(InWidgetStackTag);

				UWidget_ActivatableBase* CreatedWidget = FoundWidgetStack->AddWidget<UWidget_ActivatableBase>(
					LoadedWidgetClass,
					[AsyncPushStateCallback](UWidget_ActivatableBase& CreatedWidgetInstance)
					{
						AsyncPushStateCallback(EAsyncPushWidgetState::OnCreatedPrePush, &CreatedWidgetInstance);
					}
				);

				AsyncPushStateCallback(EAsyncPushWidgetState::PostPush, CreatedWidget);
			}
		)
	);
}
