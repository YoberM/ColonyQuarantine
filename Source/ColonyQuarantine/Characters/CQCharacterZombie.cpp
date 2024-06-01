// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCharacterZombie.h"

ACQCharacterZombie::ACQCharacterZombie() /*: ACQCharacter()*/
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("ACQCharacterZombie created: %s"), *GetName());
}

void ACQCharacterZombie::BeginPlay()
{
	Super::BeginPlay();
	// TODO: Implement AI, should initialize and register on AI Director
}
