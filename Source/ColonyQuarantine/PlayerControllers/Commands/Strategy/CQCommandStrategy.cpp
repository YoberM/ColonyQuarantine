// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandStrategy.h"

#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"



bool UCQCommandStrategy::CanExecuteCommand()
{
	if (Super::CanExecuteCommand())
	{
		return BaseController->GetCurrentMode() == EPlayerControllerMode::StrategyMode;
	}
	return false;
}

void UCQCommandStrategy::ExecuteCommand(const FInputActionValue& Value)
{
	Super::ExecuteCommand(Value);
}

bool UCQCommandStrategy::CanReleaseCommand()
{
	if (Super::CanReleaseCommand())
		return BaseController->GetCurrentMode() == EPlayerControllerMode::StrategyMode;
	return false;
}
