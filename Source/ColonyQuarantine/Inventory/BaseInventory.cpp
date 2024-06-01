// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInventory.h"

#include "BaseSlot.h"
#include "ColonyQuarantine/Item/BaseItem.h"

// Sets default values
UBaseInventory::UBaseInventory()
{
	bWantsInitializeComponent = true;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void UBaseInventory::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseInventory::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

EAddItemResult UBaseInventory::AddItem(uint8 SlotIndex, ABaseItem* Item, uint8 Quantity)
{
	if (Slots[SlotIndex] == nullptr)
	{
		return EAddItemResult::Error;
	}

	if (Slots[SlotIndex]->HasItem())
	{
		bool bIsSameItem = Slots[SlotIndex]->GetItem()->CheckIfSameItem(Item);
		if (!bIsSameItem)
		{
			return EAddItemResult::OtherItem;
		}
		bool bAddedAmount = Slots[SlotIndex]->AddAmount(Quantity);
		if (!bAddedAmount)
		{
			return EAddItemResult::MaxStack;
		}
		return EAddItemResult::Added;
	}
	else
	{
		Slots[SlotIndex]->AddItem(Item,Quantity);
		return EAddItemResult::Added;
	}
}

void UBaseInventory::GetSlotByIndex(uint8 SlotIndex)
{
}

void UBaseInventory::GetSlotByItem(ABaseItem* Item)
{
}

ABaseSlot* UBaseInventory::GetNearestFreeSlotToBegin(ABaseItem* Item)
{
	for (int i = 0; i < MaxSlots; ++i)
	{
		if (Slots[i] && !Slots[i]->HasItem())
		{
			return Slots[i];
		}
	}
	return nullptr;
}

void UBaseInventory::SetupData(uint8 NumOfSlots)
{
	MaxSlots = NumOfSlots;
	Slots.SetNum(MaxSlots);
	for (int i = 0; i < MaxSlots; ++i)
	{
		Slots.Add(NewObject<ABaseSlot>());
	}
}
