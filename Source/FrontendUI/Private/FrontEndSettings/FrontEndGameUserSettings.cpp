// Copyright Gravity Well Games, LLC All Rights Reserved


#include "FrontEndSettings/FrontendGameUserSettings.h"

UFrontEndGameUserSettings* UFrontEndGameUserSettings::Get()
{	
	if (GEngine)
	{
		return CastChecked<UFrontEndGameUserSettings>(GEngine->GetGameUserSettings());
	}

	return nullptr;
}