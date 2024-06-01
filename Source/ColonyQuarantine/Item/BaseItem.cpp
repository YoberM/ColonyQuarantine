// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************

#include "BaseItem.h"

// Sets default values
ABaseItem::ABaseItem()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));

	VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Component"));
	VisualComponent->SetupAttachment(RootComponent);

	CollisionComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Component"));
	CollisionComponent->SetupAttachment(RootComponent);

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

EActionStatus ABaseItem::TryUseItem()
{
	if(CanUseItem())
	{
		UseItem();
		return EActionStatus::Success;
	}
	return EActionStatus::Failed;
}

bool ABaseItem::CanUseItem()
{
	return true;
}

void ABaseItem::UseItem()
{
	// Something
}

bool ABaseItem::CheckIfSameItem(ABaseItem* NewItem)
{
	if (NewItem->ItemName.Equals(ItemName))
	{
		return true;
	}
	return false;
}

// Called when the game starts or when spawned
void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

