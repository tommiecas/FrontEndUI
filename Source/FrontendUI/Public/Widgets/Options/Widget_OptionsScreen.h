// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Widget_ActivatableBase.h"
#include "Widget_OptionsScreen.generated.h"

class UOptionsDataRegistry;
class UFrontEndTabListWidgetBase;
class UFrontEndCommonListView;
/**
 * 
 */
UCLASS(Abstract, BlueprintType, meta = (DisableNativeTick))
class FRONTENDUI_API UWidget_OptionsScreen : public UWidget_ActivatableBase
{
	GENERATED_BODY()

protected:
	//~ Begin UUserWidget Interface
	virtual void NativeOnInitialized() override;
	//~ End UUserWidget Interface

	//~ Begin UCommonActivatableWidget Interface
	virtual void NativeOnActivated() override;
	//~ End UCommonActivatableWidget Interface

private:
	UOptionsDataRegistry* GetOrCreateDataRegistry();
	
	void OnResetBoundActionTriggered();
	void OnBackBoundActionTriggered();

	UFUNCTION()
	void OnOptionsTabSelected(FName TabID);

	// ***** Bound Widgets ***** //
	UPROPERTY(meta = (BindWidget))
	UFrontEndTabListWidgetBase* TabListWidget_OptionsTabs;

	UPROPERTY(meta = (BindWidget))
	UFrontEndCommonListView* CommonListView_OptionsList;
	// ***** Bound Widgets ***** //
	
	//Handle the creation of data in the options screen. Direct access to this variable is forbidden
	UPROPERTY(Transient)
	UOptionsDataRegistry* CreatedOwningDataRegistry;

	
	UPROPERTY(EditDefaultsOnly, Category = "Front End Options Screen", meta = (RowType = "/Script/CommonUI.CommonInputActionDataBase"))
	FDataTableRowHandle ResetAction;

	FUIActionBindingHandle ResetActionHandle;
};
