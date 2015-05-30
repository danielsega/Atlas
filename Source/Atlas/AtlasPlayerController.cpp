// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "Atlas.h"
#include "AtlasPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"

#include "AtlasCharacter.h"

AAtlasPlayerController::AAtlasPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AAtlasPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}


void AAtlasPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//--Right Click
	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AAtlasPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AAtlasPlayerController::OnSetDestinationReleased);
	//--Left Click
	InputComponent->BindAction("Select", IE_Pressed, this, &AAtlasPlayerController::OnSelectPressed);
	InputComponent->BindAction("Select", IE_Released, this, &AAtlasPlayerController::OnSelectReleased);
	//--WheelUp
	InputComponent->BindAction("ZoomCamaraUp", IE_Pressed, this, &AAtlasPlayerController::OnZoomCameraUpPressed);
	InputComponent->BindAction("ZoomCamaraUp", IE_Released, this, &AAtlasPlayerController::OnZoomCameraUpReleased);
	//--WheelDown
	InputComponent->BindAction("ZoomCamaraDown", IE_Pressed, this, &AAtlasPlayerController::OnZoomCameraDownPressed);
	InputComponent->BindAction("ZoomCamaraDown", IE_Released, this, &AAtlasPlayerController::OnZoomCameraDownReleased);
	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AAtlasPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AAtlasPlayerController::MoveToTouchLocation);
}

void AAtlasPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void AAtlasPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AAtlasPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const Pawn = GetPawn();
	if (Pawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, Pawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AAtlasPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AAtlasPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void AAtlasPlayerController::OnSelectPressed()
{
	
}

void AAtlasPlayerController::OnSelectReleased()
{

}

void AAtlasPlayerController::OnZoomCameraUpPressed()
{
	AAtlasCharacter* const atlasChar = Cast<AAtlasCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	atlasChar->GetCameraBoom()->TargetArmLength -= 100;
}

void AAtlasPlayerController::OnZoomCameraUpReleased()
{

}

void AAtlasPlayerController::OnZoomCameraDownPressed()
{
	AAtlasCharacter* const atlasChar = Cast<AAtlasCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	atlasChar->GetCameraBoom()->TargetArmLength += 100;
}

void AAtlasPlayerController::OnZoomCameraDownReleased()
{

}