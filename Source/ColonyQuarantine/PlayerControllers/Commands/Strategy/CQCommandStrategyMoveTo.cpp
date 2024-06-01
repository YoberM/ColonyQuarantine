// Fill out your copyright notice in the Description page of Project Settings.


#include "CQCommandStrategyMoveTo.h"

#include "NiagaraFunctionLibrary.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "ColonyQuarantine/ColonyQuarantinePlayerController.h"

void UCQCommandStrategyMoveTo::ReadData(const FInputActionValue& Value)
{
	Super::ReadData(Value);
}

void UCQCommandStrategyMoveTo::ExecuteCommand(const FInputActionValue& Value)
{
	Super::ExecuteCommand(Value);
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input 
	FHitResult Hit;
	bool bHitSuccessful = BaseController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	APawn* ControlledPawn = BaseController->GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation());
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void UCQCommandStrategyMoveTo::ReleaseCommand()
{
	Super::ReleaseCommand();
	BaseController->StopMovement();
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(BaseController.Get(), CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}
