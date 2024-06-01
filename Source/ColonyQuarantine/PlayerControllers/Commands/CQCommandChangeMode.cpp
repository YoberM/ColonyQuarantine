// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandChangeMode.h"

#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"

bool UCQCommandChangeMode::CanExecuteCommand()
{
	if (Super::CanExecuteCommand())
	{
		switch (BaseController->GetCurrentMode())
		{
			case EPlayerControllerMode::ControllingSurvivor:
			case EPlayerControllerMode::StrategyMode:
				return true;
			case EPlayerControllerMode::SpectatorMode:
				break;
			case EPlayerControllerMode::PausedMode:
				break;
			case EPlayerControllerMode::Blocked:
				break;
			default:
				return false;
		}
	}
	return Super::CanExecuteCommand();
}

void UCQCommandChangeMode::ExecuteCommand(const FInputActionValue& Value)
{
	Super::ExecuteCommand(Value);
	HandleChangeMode();
}

void UCQCommandChangeMode::HandleChangeMode()
{
	BaseController->StopMovement();
	switch (BaseController->GetCurrentMode())
	{
		case EPlayerControllerMode::ControllingSurvivor:
			BaseController->SetCurrentMode(EPlayerControllerMode::StrategyMode);
			break;
		case EPlayerControllerMode::StrategyMode:
			BaseController->SetCurrentMode(EPlayerControllerMode::ControllingSurvivor);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("UCQCommandChangeMode::HandleChangeMode Invalid mode"));
	}
}
