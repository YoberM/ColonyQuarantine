// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "ColonyQuarantine/Gamemodes/BaseGameMode.h"
#include "ColonyQuarantine/Interaction/BaseInteractable.h"
#include "ColonyQuarantine/Inventory/BaseInventory.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	UE_LOG(LogTemp, Warning, TEXT("ABaseCharacter created: %s"), *GetName());
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ABaseGameMode* GM = Cast<ABaseGameMode>(GetWorld()->GetAuthGameMode()); GM && GM->bDebugMode)
	{
		DrawDebugDirectionalArrow(GetWorld(),GetActorLocation(),GetActorLocation() + GetActorRotation().Vector().GetSafeNormal2D()*100.0f,10.f,FColor::Yellow,false,0.0f,0,1.5f);
		DrawDebugDirectionalArrow(GetWorld(),GetActorLocation(),GetActorLocation() + (GetActorRotation()+FRotator(0,90,0)).Vector().GetSafeNormal2D()*100.0f,10.f,FColor::Orange,false,0.0f,0,1.5f);
	}

}

void ABaseCharacter::AddMovementInput(FVector WorldDirection, float ScaleValue, bool bForce)
{
	Super::AddMovementInput(WorldDirection, ScaleValue, bForce);
	if (ABaseGameMode* GM = Cast<ABaseGameMode>(GetWorld()->GetAuthGameMode()); GM && GM->bDebugMode)
		DrawDebugDirectionalArrow(GetWorld(),GetActorLocation(),GetActorLocation() + WorldDirection.GetSafeNormal2D() * 100.0f,10.f,FColor::Green,false,0.0f,0,1.5f);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

