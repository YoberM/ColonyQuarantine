// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandBase.h"
#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"

UCQCommandBase::UCQCommandBase()
{
}

UCQCommandBase::UCQCommandBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	
}

UCQCommandBase::UCQCommandBase(TWeakObjectPtr<AColonyQuarantinePlayerController> NewBaseController)
{
	BaseController = NewBaseController;
}

void UCQCommandBase::Initialize(TWeakObjectPtr<UObject> NewBaseController)
{
	if (NewBaseController.IsValid())
	{
		TWeakObjectPtr<class AColonyQuarantinePlayerController> TempBaseController = Cast<AColonyQuarantinePlayerController>(NewBaseController);
		if (TempBaseController.IsValid())
		{
			BaseController = TempBaseController;
		}

	}
	bIsDebugging = true;
}

void UCQCommandBase::ReadData(const FInputActionValue& Value)
{
	// Get the value of the input action
}

void UCQCommandBase::TryExecuteCommand(const FInputActionValue& Value)
{
	ReadData(Value);
	if (CanExecuteCommand())
	{
		ExecuteCommand(Value);
	}
	else
		CommandStatus = ECommandStatus::Failed;
}

bool UCQCommandBase::CanExecuteCommand()
{
	return BaseController.IsValid();
}

void UCQCommandBase::ExecuteCommand(const FInputActionValue& Value)
{
	if (bIsDebugging)
	{
		GEngine->AddOnScreenDebugMessage(-1, DebugMessageDuration, FColor::Green, FString::Printf(TEXT("Command %s executed"), *GetClass()->GetName()));
	}
	CommandStatus = ECommandStatus::Executed;
}

bool UCQCommandBase::CanReleaseCommand()
{
	return BaseController.IsValid();
}

void UCQCommandBase::ReleaseCommand()
{
	if (CanReleaseCommand())
	{
		if (bIsDebugging)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Silver, FString::Printf(TEXT("Command %s released"), *GetClass()->GetName()));
		}
		CommandStatus = ECommandStatus::Released;
	}
}
