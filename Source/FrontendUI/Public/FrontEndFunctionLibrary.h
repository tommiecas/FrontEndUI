// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "FrontEndFunctionLibrary.generated.h"

class UWidget_ActivatableBase;

/**
 * 
 */
UCLASS()
class FRONTENDUI_API UFrontEndFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, Category = "FrontEnd Function Library")
	static TSoftClassPtr<UWidget_ActivatableBase> GetFrontEndSoftWidgetClassByTag( UPARAM(meta = (Categories = "FrontEnd.Widget")) FGameplayTag InWidgetTag);
};
