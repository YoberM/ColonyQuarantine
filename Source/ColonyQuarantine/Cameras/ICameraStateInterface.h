// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/Interface.h"
#include "ICameraStateInterface.generated.h"

UINTERFACE()
class COLONYQUARANTINE_API UCameraStateInterface : public UInterface 
{
	GENERATED_UINTERFACE_BODY()
public:
	UCameraStateInterface();
};

class COLONYQUARANTINE_API ICameraStateInterface 
{
	GENERATED_IINTERFACE_BODY()
public:
	ICameraStateInterface();
	virtual void InitializeCamera() = 0;
	virtual void UpdateCamera() = 0;
};
