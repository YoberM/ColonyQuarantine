// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCharacterSurvivor.h"

ACQCharacterSurvivor::ACQCharacterSurvivor()
{
	PrimaryActorTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("ACQCharacterSurvivor created: %s"), *GetName());
}

void ACQCharacterSurvivor::BeginPlay()
{
	Super::BeginPlay();
}
