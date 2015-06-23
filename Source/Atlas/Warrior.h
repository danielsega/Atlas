// Atlas - Daniel Sega Mattos

#pragma once

#include "GameFramework/Character.h"
#include "AtlasCharacter.h"
#include "EntityWarrior.h"
#include "Warrior.generated.h"

UCLASS()
class ATLAS_API AWarrior : public AAtlasCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	//AWarrior();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
