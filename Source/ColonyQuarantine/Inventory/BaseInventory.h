// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseInventory.generated.h"

UENUM()
enum class EAddItemResult: uint8
{
	Added,
	OtherItem,
	MaxStack,
	Error,
};

UCLASS()
class COLONYQUARANTINE_API UBaseInventory : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UBaseInventory();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	// If just in case method
	virtual EAddItemResult AddItem(uint8 SlotIndex, class ABaseItem* Item,uint8 Quantity = 1);
	virtual void GetSlotByIndex(uint8 SlotIndex);
	virtual void GetSlotByItem(class ABaseItem* Item);
	virtual class ABaseSlot* GetNearestFreeSlotToBegin(class ABaseItem* Item);

	virtual void SetupData(uint8 NumOfSlots);
	UPROPERTY(EditAnywhere,Transient)
	TArray<class ABaseSlot*> Slots;
	UPROPERTY(EditAnywhere)
	uint8 MaxSlots;
	UPROPERTY(EditAnywhere)
	uint8 CurrentSlots;
	UActorComponent * Owner;
};
