// Atlas - Daniel Sega Mattos

#include "Atlas.h"
#include "AtlasHUD.h"

#include "Engine/Font.h"
#include "Engine/Canvas.h"

AAtlasHUD::AAtlasHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	/*static ConstructorHelpers::FObjectFinder<UFont>HUDFontOb(TEXT("/Game/Atlas/Font/Atlas"));
	FontHUD = HUDFontOb.Object;*/
	isMouseBeingDragged = false;
}

void AAtlasHUD::DrawHUD()
{
	Super::DrawHUD();
	
	if (isMouseBeingDragged)
	{
		DrawSelectBox(mouseDragStartX, mouseDragStartY, mouseDragEndX, mouseDragEndY);
	}
}


void AAtlasHUD::DrawSelectBox(float StartScreenX, float StartScreenY, float EndScreenX, float EndScreenY, FLinearColor LineColor)
{
	DrawLine(StartScreenX, StartScreenY, EndScreenX, StartScreenY, LineColor);
	DrawLine(StartScreenX, StartScreenY, StartScreenX, EndScreenY, LineColor);
	DrawLine(EndScreenX, StartScreenY, EndScreenX, EndScreenY, LineColor);
	DrawLine(StartScreenX, EndScreenY, EndScreenX, EndScreenY, LineColor);
}

//--This will update the values from the mouse on the controller side. The values are initilized as the first click location.
void AAtlasHUD::MouseDragBoxOn(const float startX, const float startY)
{
	mouseDragStartX = startX;
	mouseDragStartY = startY;
	isMouseBeingDragged = true;
}

//--The mouse is released
void AAtlasHUD::MouseDragBoxOff()
{
	isMouseBeingDragged = false;
}

//--This will update the values from the mouse on the controller side. The values are being updates to draw the box select.
void AAtlasHUD::SetMouseDragCoor(const float updateEndX, const float updateEndY)
{
	mouseDragEndX = updateEndX;
	mouseDragEndY = updateEndY;
}
;