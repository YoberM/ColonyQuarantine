// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSlot.h"

#include "ColonyQuarantine/Item/BaseItem.h"

// Sets default values
ABaseSlot::ABaseSlot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseSlot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABaseSlot::AddItem(ABaseItem* NewItem, uint8 Quantity)
{
	if (SlotData.Item == nullptr)
	{
		SlotData.Item = NewItem;
		return true;
	}

	if (SlotData.Item->CheckIfSameItem(NewItem))
	{
		AddAmount(Quantity);
		return true;
	}
	return false;
}

//ABaseItem* ABaseSlot::ChangeItem(ABaseItem* NewItem, uint8 NewAmount)
//{
//	ABaseItem* TempItem = Item;
//	Item = NewItem;
//	ItemsQuantity = NewAmount;
//	return TempItem;
//}

bool ABaseSlot::AddAmount(uint8 Quantity)
{
	if (SlotData.ItemsQuantity + Quantity > SlotData.Item->MaxStackNum)
		return false;
	SlotData.ItemsQuantity += Quantity;
	return true;
}


