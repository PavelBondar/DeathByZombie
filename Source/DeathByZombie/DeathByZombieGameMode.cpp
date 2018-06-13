// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "DeathByZombieGameMode.h"
#include "DeathByZombieHUD.h"
#include "DeathByZombieCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADeathByZombieGameMode::ADeathByZombieGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ADeathByZombieHUD::StaticClass();
}
