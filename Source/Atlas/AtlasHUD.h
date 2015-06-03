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

		virtual void DrawHUD() override;
};
