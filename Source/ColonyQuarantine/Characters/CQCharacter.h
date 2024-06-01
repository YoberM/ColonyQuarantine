// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "ColonyQuarantine/Inventory/BaseInventory.h"
#include "CQCharacter.generated.h"

UCLASS()
class COLONYQUARANTINE_API ACQCharacter : public ABaseCharacter
{
	GENERATED_BODY()
public:
	ACQCharacter();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	// **********************************
	// ******** ITEM INTERACTION ********
	// **********************************
	virtual bool TryPickUpItem();
	virtual bool CanPickUpItem();
	virtual void PickUpItem();

	virtual bool TryThrowItem();
	virtual bool CanThrowItem();
	virtual void ThrowItem();
	// **********************************
	// ******** ITEM INTERACTION ********
	// **********************************

	virtual void AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce = false) override;
protected:

	UPROPERTY(EditAnywhere,Transient)
	class UCQInteractable* Interactable { nullptr };
	
	UPROPERTY(EditAnywhere,Transient)
	class UBaseInventory* Inventory { nullptr };

};
