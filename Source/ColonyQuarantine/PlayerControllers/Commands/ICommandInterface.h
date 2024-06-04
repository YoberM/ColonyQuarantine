// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "ICommandInterface.generated.h"

struct FInputActionValue;

UINTERFACE()
class COLONYQUARANTINE_API UCommandInterface : public UInterface 
{
	GENERATED_UINTERFACE_BODY()
public:
	UCommandInterface();
};

class COLONYQUARANTINE_API ICommandInterface 
{
	GENERATED_IINTERFACE_BODY()
public:
	ICommandInterface();
	virtual void Initialize(TWeakObjectPtr<class UObject> InBaseController) = 0;
	virtual void ExecuteCommand(const FInputActionValue& Value) = 0;
	virtual void ReleaseCommand() = 0;
};
