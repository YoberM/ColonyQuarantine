// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGameMode.h"
#include "CQGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API ACQGameMode : public ABaseGameMode
{
	GENERATED_BODY()
public:
	// Something
	virtual void GetAllCharacters() override;
private:
	UPROPERTY(EditAnywhere)
	TArray<class ACQCharacterSurvivor*> Survivors;
	UPROPERTY(EditAnywhere)
	TArray<class ACQCharacterZombie*> Zombies;
};
