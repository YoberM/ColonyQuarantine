// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "BaseUtility.generated.h"


UCLASS()
class COLONYQUARANTINE_API ABaseUtility : public ABaseItem
{
	GENERATED_BODY()
public:
	virtual EActionStatus TryConsume();
	virtual bool CanConsume();
	virtual void OnConsume();
};
