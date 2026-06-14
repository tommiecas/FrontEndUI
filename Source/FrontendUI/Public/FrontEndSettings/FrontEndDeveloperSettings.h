// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "FrontEndDeveloperSettings.generated.h"

class UWidget_ActivatableBase;

/**
 * 
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Front End UI Settings"))
class FRONTENDUI_API UFrontEndDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()


public:
	UPROPERTY(Config, EditAnywhere, Category = "Widget Reference", meta = (ForceInlineRow, Categories = "FrontEnd.Widget"))
	TMap< FGameplayTag,TSoftClassPtr<UWidget_ActivatableBase> > FrontEndWidgetMap;	

	
	UPROPERTY(Config, EditAnywhere, Category = "Options Image Reference", meta = (ForceInlineRow, Categories = "Frontend.Image"))
	TMap< FGameplayTag, TSoftObjectPtr<UTexture2D> > OptionsScreenSoftImageMap;
};
