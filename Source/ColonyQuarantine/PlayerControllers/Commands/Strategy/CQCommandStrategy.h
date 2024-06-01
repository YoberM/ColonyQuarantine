// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColonyQuarantine/PlayerControllers/Commands/CQCommandBase.h"
#include "CQCommandStrategy.generated.h"


UCLASS(Blueprintable)
class COLONYQUARANTINE_API UCQCommandStrategy : public UCQCommandBase 
{
	GENERATED_BODY()
public:
	virtual bool CanExecuteCommand() override;
	virtual void ExecuteCommand(const FInputActionValue& Value) override;
	virtual bool CanReleaseCommand() override;
};
