// Copyright Gravity Well Games, LLC All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "FrontEndGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class FRONTENDUI_API UFrontEndGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

	
public:
	static UFrontEndGameUserSettings* Get();

	
	//***** Gameplay Collection Tab ***** //
	UFUNCTION()
	FString GetCurrentGameDifficulty() const { return CurrentGameDifficulty;}

	UFUNCTION()
	void SetCurrentGameDifficulty(const FString& InNewDifficulty) { CurrentGameDifficulty = InNewDifficulty;}
	//***** Gameplay Collection Tab ***** //


private:
	UPROPERTY(Config)
	FString CurrentGameDifficulty;
};
