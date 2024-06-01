// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandCharacter.h"

#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"


bool UCQCommandCharacter::CanExecuteCommand()
{
	if (Super::CanExecuteCommand())
	{
		return BaseController->GetCurrentMode() == EPlayerControllerMode::ControllingSurvivor;
	}
	return false;
}

void UCQCommandCharacter::ExecuteCommand(const FInputActionValue& Value)
{
	Super::ExecuteCommand(Value);
}

bool UCQCommandCharacter::CanReleaseCommand()
{
	if (Super::CanReleaseCommand())
		return BaseController->GetCurrentMode() == EPlayerControllerMode::StrategyMode;
	return false;
}