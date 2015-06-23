// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Atlas.h"
#include "AtlasGameMode.h"
#include "AtlasPlayerController.h"
#include "AtlasCharacter.h"
#include "AtlasHUD.h"

AAtlasGameMode::AAtlasGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	// use our custom PlayerController class
	PlayerControllerClass = AAtlasPlayerController::StaticClass();
	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Atlas/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	HUDClass = AAtlasHUD::StaticClass();
}