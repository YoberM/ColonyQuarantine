// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************

#pragma once

#include "CoreMinimal.h"
#include "Gamemodes/CQGameMode.h"
#include "ColonyQuarantineGameMode.generated.h"


UCLASS(minimalapi)
class AColonyQuarantineGameMode : public ACQGameMode
{
	GENERATED_BODY()

public:
	AColonyQuarantineGameMode();
	virtual void BeginPlay() override;
};

