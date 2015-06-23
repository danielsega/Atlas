// Atlas - Daniel Sega Mattos

#pragma once

#include "GameFramework/HUD.h"
#include "AtlasHUD.generated.h"

/**
 *
 */
UCLASS()
class ATLAS_API AAtlasHUD : public AHUD
{
	GENERATED_BODY()

public:
	AAtlasHUD(const FObjectInitializer& ObjectInitializer);
	virtual void DrawHUD() override;

	/** This will start the box drag drawing and initiliaze the start location of the box drag line drawing*/
	void MouseDragBoxOn(const float startX, const float startY);

	/** This will stop the  of the box drag line drawing*/
	void MouseDragBoxOff();

	/** This will update the coordinate from the end of the box drag line drawing*/
	void SetMouseDragCoor(const float updateEndX, const float updateEndY);
public:	

private:
	void DrawSelectBox(const float StartScreenX, const float StartScreenY, const float EndScreenX, const float EndScreenY, FLinearColor LineColor = FColor::Green);
private:
	//UFont *FontHUD;

	/** if the mouse is being drag it will activate the drawHUD function*/
	bool isMouseBeingDragged;

	//** Mouse Drag*/
	float mouseDragStartX;
	float mouseDragStartY;
	float mouseDragEndX;
	float mouseDragEndY;
};
