// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CQCommandCharacter.h"
#include "CQCommandCharacterMove.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API UCQCommandCharacterMove : public UCQCommandCharacter
{
	GENERATED_BODY()
public:
	virtual void ReadData(const FInputActionValue& Value) override;
	virtual void ExecuteCommand(const FInputActionValue& Value) override;

protected:
	FVector2D DirectionToMove;
};
