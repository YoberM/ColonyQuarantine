// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandCharacterMove.h"

#include "InputActionValue.h"
#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"

void UCQCommandCharacterMove::ReadData(const FInputActionValue& Value)
{
	Super::ReadData(Value);
	DirectionToMove = Value.Get<FVector2D>();
}

void UCQCommandCharacterMove::ExecuteCommand(const FInputActionValue& Value)
{
	Super::ExecuteCommand(Value);
	APawn* ControlledPawn = BaseController->GetPawn();
	if (ControlledPawn != nullptr)
	{
		ControlledPawn->AddMovementInput(FVector(DirectionToMove,0), 1.0, false);
	}
}
