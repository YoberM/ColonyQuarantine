// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "BaseCameraActor.generated.h"

UENUM(Blueprintable)
enum class ECameraMode :	uint8
{
	FreeMode,
	FollowMode,
	TopDownMode,
	SpectatorMode,
	OrbitMode,
};

class UCameraStateBase;
UCLASS()
class COLONYQUARANTINE_API ABaseCameraActor : public ACameraActor
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
	UCameraStateBase* CurrentState;
};
