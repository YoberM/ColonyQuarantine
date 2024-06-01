// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CQCommandBase.h"
#include "CQCommandChangeMode.generated.h"


enum class EPlayerControllerMode : uint8;

UCLASS()
class COLONYQUARANTINE_API UCQCommandChangeMode : public UCQCommandBase
{
	GENERATED_BODY()
public:
	virtual bool CanExecuteCommand() override;
	virtual void ExecuteCommand(const FInputActionValue& Value) override;
	virtual void HandleChangeMode();
};
