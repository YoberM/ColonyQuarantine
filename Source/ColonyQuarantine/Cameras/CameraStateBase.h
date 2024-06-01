// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICameraStateInterface.h"
#include "CameraStateBase.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API UCameraStateBase : public UObject, public ICameraStateInterface
{
	GENERATED_BODY()
public:
	virtual void PostInitProperties() override;
	virtual void InitializeCamera() override;
	virtual void UpdateCamera() override;
};
