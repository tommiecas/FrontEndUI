// Copyright Gravity Well Games, LLC All Rights Reserved


#include "FrontEndFunctionLibrary.h"
#include "FrontEndSettings/FrontEndDeveloperSettings.h"


TSoftClassPtr<UWidget_ActivatableBase> UFrontEndFunctionLibrary::GetFrontEndSoftWidgetClassByTag(UPARAM(meta = (Categories = "FrontEnd.Widget")) FGameplayTag InWidgetTag)
{	
	const UFrontEndDeveloperSettings* FrontEndDeveloperSettings = GetDefault<UFrontEndDeveloperSettings>();

	checkf(FrontEndDeveloperSettings->FrontEndWidgetMap.Contains(InWidgetTag),TEXT("Could not find the corresponding widget under the tag %s"), *InWidgetTag.ToString());

	return FrontEndDeveloperSettings->FrontEndWidgetMap.FindRef(InWidgetTag);
}


TSoftObjectPtr<UTexture2D> UFrontEndFunctionLibrary::GetOptionsSoftImageByTag(FGameplayTag InImageTag)
{
	const UFrontEndDeveloperSettings* FrontendDeveloperSettings = GetDefault<UFrontEndDeveloperSettings>();

	checkf(FrontendDeveloperSettings->OptionsScreenSoftImageMap.Contains(InImageTag),TEXT("Could not find an image associated with tag %s"),*InImageTag.ToString());

	return FrontendDeveloperSettings->OptionsScreenSoftImageMap.FindRef(InImageTag);

}
