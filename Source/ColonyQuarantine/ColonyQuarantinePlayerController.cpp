// Copyright Epic Games, Inc. All Rights Reserved.

#include "ColonyQuarantinePlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ColonyQuarantineCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "PlayerControllers/Commands/CQCommandBase.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AColonyQuarantinePlayerController::AColonyQuarantinePlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AColonyQuarantinePlayerController::SetCurrentMode(EPlayerControllerMode NewPlayerControllerMode)
{
	// Handle somethings for later use like VFX or SFX
	switch (CurrentMode)
	{
		case EPlayerControllerMode::ControllingSurvivor:
			break;
		case EPlayerControllerMode::StrategyMode:
			break;
		case EPlayerControllerMode::SpectatorMode:
			break;
		case EPlayerControllerMode::PausedMode:
			break;
		case EPlayerControllerMode::Blocked:
			break;
	}
	CurrentMode = NewPlayerControllerMode;
}

void AColonyQuarantinePlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	// Safe
	Commands.Empty();
	for (auto Command : CommandsToInitialize)
	{
		if (Command.Value.Command)
		{
			UCQCommandBase* NewObjectInstance = NewObject<UCQCommandBase>(this,Command.Value.Command);
			NewObjectInstance->Initialize(this);
			SetupCommandOnInputComponent(Command.Key,NewObjectInstance,Command.Value.TriggerEvent);
			Commands.Add(NewObjectInstance);
		}
	}

}

void AColonyQuarantinePlayerController::SetupCommandOnInputComponent(UInputAction* InputActionToSetup, UCQCommandBase* CommandToSetup, ETriggerEvent TriggerEvent)
{
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(InputActionToSetup, TriggerEvent, CommandToSetup, &UCQCommandBase::TryExecuteCommand);
		EnhancedInputComponent->BindAction(InputActionToSetup, ETriggerEvent::Completed, CommandToSetup, &UCQCommandBase::ReleaseCommand);
	}
}

void AColonyQuarantinePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		//EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AColonyQuarantinePlayerController::OnInputStarted);
		//EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AColonyQuarantinePlayerController::OnSetDestinationTriggered);
		//EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AColonyQuarantinePlayerController::OnSetDestinationReleased);
		//EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AColonyQuarantinePlayerController::OnSetDestinationReleased);

		//// Setup touch input events
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &AColonyQuarantinePlayerController::OnInputStarted);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &AColonyQuarantinePlayerController::OnTouchTriggered);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &AColonyQuarantinePlayerController::OnTouchReleased);
		//EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &AColonyQuarantinePlayerController::OnTouchReleased);
		
		//EnhancedInputComponent->BindAction(SetDestinationUpDownAction, ETriggerEvent::Started, this, &AColonyQuarantinePlayerController::OnSetDestinationMovementStarted);
		//EnhancedInputComponent->BindAction(SetDestinationUpDownAction, ETriggerEvent::Triggered, this, &AColonyQuarantinePlayerController::OnSetDestinationMovementTriggered);
		//EnhancedInputComponent->BindAction(SetDestinationUpDownAction, ETriggerEvent::Ongoing, this, &AColonyQuarantinePlayerController::OnSetDestinationMovementOnGoing);
		//EnhancedInputComponent->BindAction(SetDestinationUpDownAction, ETriggerEvent::Completed, this, &AColonyQuarantinePlayerController::OnSetDestinationMovementReleased);

		//EnhancedInputComponent->BindAction(OnChangeModeAction, ETriggerEvent::Completed, this, &AColonyQuarantinePlayerController::OnChangeModeActionStarted);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}


void AColonyQuarantinePlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AColonyQuarantinePlayerController::OnSetDestinationTriggered()
{
	if (CurrentMode != EPlayerControllerMode::StrategyMode)
		return;
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input 
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AColonyQuarantinePlayerController::OnSetDestinationReleased()
{
	if (CurrentMode != EPlayerControllerMode::StrategyMode)
		return;
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AColonyQuarantinePlayerController::OnTouchTriggered()
{
	if (CurrentMode != EPlayerControllerMode::StrategyMode)
		return;
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AColonyQuarantinePlayerController::OnTouchReleased()
{
	if (CurrentMode != EPlayerControllerMode::StrategyMode)
		return;
	bIsTouch = false;
	OnSetDestinationReleased();
}

void AColonyQuarantinePlayerController::OnSetDestinationMovementStarted(const FInputActionValue& Value)
{
	if (CurrentMode != EPlayerControllerMode::ControllingSurvivor)
		return;
	FVector2D InputValue = Value.Get<FVector2D>();

	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		ControlledPawn->AddMovementInput(FVector(InputValue,0), 1.0, false);
	}
}

void AColonyQuarantinePlayerController::OnSetDestinationMovementTriggered(const FInputActionValue& Value)
{
	if (CurrentMode != EPlayerControllerMode::ControllingSurvivor)
		return;
	FVector2D InputValue = Value.Get<FVector2D>();

	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		ControlledPawn->AddMovementInput(FVector(InputValue,0), 1.0, false);
	}
}

void AColonyQuarantinePlayerController::OnSetDestinationMovementOnGoing(const FInputActionValue& Value)
{
	if (CurrentMode != EPlayerControllerMode::ControllingSurvivor)
		return;
	FVector2D InputValue = Value.Get<FVector2D>();

	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		ControlledPawn->AddMovementInput(FVector(InputValue,0), 1.0, false);
	}
}

void AColonyQuarantinePlayerController::OnSetDestinationMovementReleased(const FInputActionValue& Value)
{
	if (CurrentMode != EPlayerControllerMode::ControllingSurvivor)
		return;
	FVector2D InputValue = Value.Get<FVector2D>();

	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		ControlledPawn->AddMovementInput(FVector(InputValue,0), 1.0, false);
	}
}

void AColonyQuarantinePlayerController::OnChangeModeActionStarted(const FInputActionValue& Value)
{
	// Probably will be changed by a switch
	switch (CurrentMode)
	{
	case EPlayerControllerMode::ControllingSurvivor:
		CurrentMode = EPlayerControllerMode::StrategyMode;
		break;
	case EPlayerControllerMode::StrategyMode:
		CurrentMode = EPlayerControllerMode::ControllingSurvivor;
		break;
	case EPlayerControllerMode::SpectatorMode:
		// Do Something
		break;
	case EPlayerControllerMode::PausedMode:
		// Do Something
		break;
	case EPlayerControllerMode::Blocked:
		// Should not do anything
		return;
	}
	OnChangePlayerControllerModeDelegate.ExecuteIfBound(CurrentMode);
}
