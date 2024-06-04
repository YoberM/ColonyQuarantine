// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CQCommandStrategy.h"

#include "CQCommandStrategySelect.generated.h"

UCLASS()
class COLONYQUARANTINE_API UCQCommandStrategySelect : public UCQCommandStrategy
{
	GENERATED_BODY()
public:
	virtual void ReadData(const FInputActionValue& Value) override;
	virtual void ExecuteCommand(const FInputActionValue& Value) override;
	virtual void ReleaseCommand() override;
};
