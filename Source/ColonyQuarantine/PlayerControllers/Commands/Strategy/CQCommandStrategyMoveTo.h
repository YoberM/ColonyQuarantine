// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CQCommandStrategy.h"
#include "CQCommandStrategyMoveTo.generated.h"

/**
 * 
 */
UCLASS()
class COLONYQUARANTINE_API UCQCommandStrategyMoveTo : public UCQCommandStrategy
{
	GENERATED_BODY()
public:
	virtual void ReadData(const FInputActionValue& Value) override;
	virtual void ExecuteCommand(const FInputActionValue& Value) override;
	virtual void ReleaseCommand() override;
protected:
	UPROPERTY(EditAnywhere)
	FVector CachedDestination { FVector::ZeroVector };
	UPROPERTY(EditAnywhere)
	float FollowTime { 0.0f };
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold { 0.25f };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;

};
