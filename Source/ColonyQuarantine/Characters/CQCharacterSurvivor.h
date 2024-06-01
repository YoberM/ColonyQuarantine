// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CQCharacter.h"
#include "CQCharacterSurvivor.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API ACQCharacterSurvivor : public ACQCharacter
{
	GENERATED_BODY()
public:
	ACQCharacterSurvivor();
	virtual void BeginPlay() override;
};
