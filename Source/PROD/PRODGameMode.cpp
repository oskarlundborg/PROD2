// Copyright Epic Games, Inc. All Rights Reserved.

#include "PRODGameMode.h"
#include "PRODCharacter.h"
#include "UObject/ConstructorHelpers.h"

APRODGameMode::APRODGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter_Alexander"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
