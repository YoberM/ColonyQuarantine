// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CQCharacter.h"
#include "CQCharacterZombie.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API ACQCharacterZombie : public ACQCharacter
{
	GENERATED_BODY()
public:
	ACQCharacterZombie();
	virtual void BeginPlay() override;
};
