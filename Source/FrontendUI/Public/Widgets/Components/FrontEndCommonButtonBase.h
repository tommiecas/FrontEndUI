// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "FrontEndCommonButtonBase.generated.h"

class UCommonTextBlock;

/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class FRONTENDUI_API UFrontEndCommonButtonBase : public UCommonButtonBase
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable)
	void SetButtonText(FText InText);

	UFUNCTION(BlueprintCallable)
	FText GetButtonDisplayText() const;

private:
	//~ Begin UUserWidget Interface
	virtual void NativePreConstruct() override;
	//~ End UUserWidget Interface

	//~ Begin UCommonButtonBase Interface
	virtual void NativeOnCurrentTextStyleChanged() override;
	virtual void NativeOnHovered() override;
	virtual void NativeOnUnhovered() override;
	//~ End UCommonButtonBaseInterface
	
	//**** Bound Widgets ****//
	UPROPERTY(meta = (BindWidgetOptional))
	UCommonTextBlock* CommonTextBlock_ButtonText;
	//**** Bound Widgets ****//

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Frontend Button", meta = (AllowPrivateAccess = "true"))
	FText ButtonDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FrontEnd Button", meta = (AllowPrivateAccess = "true"))
	bool bUpperCaseButtonText = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FrontEnd Button", meta = (AllowPrivateAccess = "true"))
	FText ButtonDescriptionText;
};	
