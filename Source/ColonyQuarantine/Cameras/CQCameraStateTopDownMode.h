// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CameraStateBase.h"
#include "CQCameraStateTopDownMode.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API UCQCameraStateTopDownMode : public UCameraStateBase
{
	GENERATED_BODY()
public:
	virtual void PostInitProperties() override;
	virtual void InitializeCamera() override;
	virtual void UpdateCamera() override;
};
