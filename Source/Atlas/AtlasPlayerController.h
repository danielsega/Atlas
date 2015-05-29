// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/PlayerController.h"
#include "AtlasPlayerController.generated.h"

UCLASS()
class AAtlasPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAtlasPlayerController(const FObjectInitializer& ObjectInitializer);

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	/** Input handlers for Select action. */
	void OnSelectPressed();
	void OnSelectReleased();

	/** Input handlers for Select action. */
	void OnZoomCameraUpPressed();
	void OnZoomCameraUpReleased();

	/** Input handlers for Select action. */
	void OnZoomCameraDownPressed();
	void OnZoomCameraDownReleased();
};


