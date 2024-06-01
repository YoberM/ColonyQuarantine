// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSlot.generated.h"

USTRUCT()
struct FSlotDataStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	class ABaseItem* Item;
	UPROPERTY(EditAnywhere)
	uint8 ItemsQuantity { 0 };
};

// this could be an component instead of an actor?
UCLASS()
class COLONYQUARANTINE_API ABaseSlot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSlot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	// Will work like a Stack
	virtual void Tick(float DeltaTime) override;
	virtual bool HasItem() { return SlotData.Item != nullptr; };
	virtual class ABaseItem* GetItem() { return SlotData.Item;};
	virtual bool AddItem(ABaseItem* NewItem, uint8 Quantity);
	virtual bool AddAmount(uint8 Quantity = 1);
	//virtual class ABaseItem* ChangeItem(ABaseItem* NewItem,uint8 NewAmount);
	
protected:
	UPROPERTY(EditAnywhere)
	bool bIsOccupied { false };
	UPROPERTY(EditAnywhere)
	FSlotDataStruct SlotData;
};
