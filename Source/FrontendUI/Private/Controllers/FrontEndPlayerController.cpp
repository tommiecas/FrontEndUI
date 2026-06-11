// Copyright Gravity Well Games, LLC All Rights Reserved


#include "Controllers/FrontEndPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

void AFrontEndPlayerController::OnPossess(APawn*aPawn)
{
	Super::OnPossess(aPawn);

	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsOfClassWithTag(this,ACameraActor::StaticClass(),FName("Default"),FoundCameras);

	if (!FoundCameras.IsEmpty())
	{
		SetViewTarget(FoundCameras[0]);
	}
}


