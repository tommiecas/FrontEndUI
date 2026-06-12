// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Widget_ActivatableBase.generated.h"

class AFrontEndPlayerController;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class FRONTENDUI_API UWidget_ActivatableBase : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	AFrontEndPlayerController* GetOwningFrontEndPlayerController();

private:
	TWeakObjectPtr<AFrontEndPlayerController> CachedOwningFrontEndPlayerController;
	
};
