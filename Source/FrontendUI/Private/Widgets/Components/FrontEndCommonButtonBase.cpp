// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Widgets/Components/FrontEndCommonButtonBase.h"
#include "CommonTextBlock.h"
#include "Subsystems/FrontEndUISubsystem.h"


void UFrontEndCommonButtonBase::SetButtonText(FText InText)
{
	if (CommonTextBlock_ButtonText && !InText.IsEmpty())
	{
		CommonTextBlock_ButtonText->SetText(bUpperCaseButtonText? InText.ToUpper() : InText);
	}
}

void UFrontEndCommonButtonBase::NativePreConstruct()
{
	Super::NativePreConstruct();

	SetButtonText(ButtonDisplayText);
}

void UFrontEndCommonButtonBase::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();

	if (CommonTextBlock_ButtonText && GetCurrentTextStyleClass())
	{
		CommonTextBlock_ButtonText->SetStyle(GetCurrentTextStyleClass());
	}
}

void UFrontEndCommonButtonBase::NativeOnHovered()
{
	Super::NativeOnHovered();

	if (!ButtonDescriptionText.IsEmpty())
	{
		UFrontEndUISubsystem::Get(this)->OnButtonDescriptionTextUpdated.Broadcast(this, ButtonDescriptionText);
	}
}

void UFrontEndCommonButtonBase::NativeOnUnhovered()
{
	Super::NativeOnUnhovered();

	UFrontEndUISubsystem::Get(this)->OnButtonDescriptionTextUpdated.Broadcast(this, FText::GetEmpty());
}