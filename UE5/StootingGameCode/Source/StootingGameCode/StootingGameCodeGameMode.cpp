// Copyright Epic Games, Inc. All Rights Reserved.

#include "StootingGameCodeGameMode.h"
#include "StootingGameCodeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStootingGameCodeGameMode::AStootingGameCodeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
