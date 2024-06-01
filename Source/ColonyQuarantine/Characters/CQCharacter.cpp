// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCharacter.h"

#include "ColonyQuarantine/Interaction/BaseInteractable.h"
#include "ColonyQuarantine/Interaction/CQInteractable.h"

ACQCharacter::ACQCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("ACQCharacter created: %s"), *GetName());
	Interactable = CreateDefaultSubobject<UCQInteractable>(TEXT("Interactable"));
	Interactable->AttachToComponent(GetRootComponent(),FAttachmentTransformRules::KeepRelativeTransform);
	
	Interactable->VisualComponent->SetupAttachment(Interactable);
	Interactable->CollisionComponent->SetupAttachment(Interactable);

	Inventory = CreateDefaultSubobject<UBaseInventory>(TEXT("Inventory"));
}

void ACQCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ACQCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ACQCharacter::TryPickUpItem()
{
	if (CanPickUpItem())
	{
		PickUpItem();
		return true;
	}
	return false;
}

bool ACQCharacter::CanPickUpItem()
{
	return true;
}

void ACQCharacter::PickUpItem()
{
}

bool ACQCharacter::TryThrowItem()
{
	if (CanThrowItem())
	{
		ThrowItem();
		return true;
	}
	return false;
}

bool ACQCharacter::CanThrowItem()
{
	return true;
}

void ACQCharacter::ThrowItem()
{
	//Interactable->additem();
}

void ACQCharacter::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
{
	Super::AddMovementInput(WorldDirection, ScaleValue, bForce);
}
