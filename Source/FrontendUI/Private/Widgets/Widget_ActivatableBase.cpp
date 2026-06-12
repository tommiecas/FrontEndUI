// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Widgets/Widget_ActivatableBase.h"
#include "Controllers/FrontEndPlayerController.h"

AFrontEndPlayerController* UWidget_ActivatableBase::GetOwningFrontEndPlayerController()
{
	if (!CachedOwningFrontEndPlayerController.IsValid())
	{
		CachedOwningFrontEndPlayerController = GetOwningPlayer<AFrontEndPlayerController>();
	}

	return CachedOwningFrontEndPlayerController.IsValid() ? CachedOwningFrontEndPlayerController.Get() : nullptr;
}
