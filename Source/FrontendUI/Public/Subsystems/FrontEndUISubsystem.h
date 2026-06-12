// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "FrontendTypes/FrontendEnumTypes.h"
#include "FrontEndUISubsystem.generated.h"

class UWidget_PrimaryLayout;
struct FGameplayTag;
class UWidget_ActivatableBase;
class UFrontEndCommonButtonBase;

enum class EAsyncPushWidgetState : uint8
{
	OnCreatedPrePush,
	PostPush
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnButtonDescriptionTextUpdatedDelegate, UFrontEndCommonButtonBase*, BroadcastingButton, FText, DescriptionText);
/**
 * 
 */
UCLASS()
class FRONTENDUI_API UFrontEndUISubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static UFrontEndUISubsystem* Get(const UObject* WorldContextObject);

	//~ Begin USubsyem Interface
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~ End USubsyem Interface

	UFUNCTION(BlueprintCallable)
	void RegisterCreatedPrimaryLayoutWidget(UWidget_PrimaryLayout* InCreatedWidget);

	void PushSoftWidgetToStackAsync(const FGameplayTag& InWidgetStackTag, TSoftClassPtr<UWidget_ActivatableBase> InSoftWidgetClass, TFunction<void(EAsyncPushWidgetState, UWidget_ActivatableBase*)> AsyncPushStateCallback);

	
	void PushConfirmScreenToModelStackAsync(EConfirmScreenType InScreenType,const FText& InScreenTitle,const FText& InScreenMsg,TFunction<void(EConfirmScreenButtonType)> ButtonClickedCallback);

	UPROPERTY(BlueprintAssignable)
	FOnButtonDescriptionTextUpdatedDelegate OnButtonDescriptionTextUpdated;
private:
	UPROPERTY(Transient)
	UWidget_PrimaryLayout* CreatedPrimaryLayout;
};
