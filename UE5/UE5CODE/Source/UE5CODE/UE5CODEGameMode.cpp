// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5CODEGameMode.h"
#include "UE5CODECharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5CODEGameMode::AUE5CODEGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
