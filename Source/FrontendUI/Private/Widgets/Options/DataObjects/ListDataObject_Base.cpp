// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Widgets/Options/DataObjects/ListDataObject_Base.h"
#include "FrontEndSettings/FrontEndGameUserSettings.h"

void UListDataObject_Base::InitDataObject()
{
	OnDataObjectInitialized();
}

void UListDataObject_Base::OnDataObjectInitialized()
{
	// Empty in base class. The child classes should override it to handle the initialization needed accordingly.
}


void UListDataObject_Base::NotifyListDataModified(UListDataObject_Base* ModifiedData, EOptionsListDataModifyReason ModifyReason)
{
	OnListDataModified.Broadcast(ModifiedData,ModifyReason);

	if (bShouldApplySettingsChangeImmediately)
	{
		UFrontEndGameUserSettings::Get()->ApplySettings(true);
	}
}