// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllers/BasePlayerController.h"
#include "PlayerControllers/CQPlayerController.h"
#include "ColonyQuarantinePlayerController.generated.h"

/** Forward declaration to improve compiling times */
enum class ETriggerEvent : uint8;
class UNiagaraSystem;
class UInputMappingContext;
class UInputAction;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UENUM()
enum class EPlayerControllerMode : uint8
{
	ControllingSurvivor,
	StrategyMode,
	SpectatorMode,
	PausedMode,
	Blocked,
};

USTRUCT(Blueprintable)
struct FCommandMapping
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = Input)
	TSubclassOf<class UCQCommandBase> Command;
	UPROPERTY(EditAnywhere, Category = Input)
	ETriggerEvent TriggerEvent { ETriggerEvent::Triggered};
};


DECLARE_DELEGATE_OneParam(FOnChangePlayerControllerMode, EPlayerControllerMode)

UCLASS()
class AColonyQuarantinePlayerController : public ACQPlayerController
{
	GENERATED_BODY()

public:
	AColonyQuarantinePlayerController();
	virtual void SetCurrentMode(EPlayerControllerMode NewPlayerControllerMode);
	EPlayerControllerMode GetCurrentMode() const { return CurrentMode; }

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	float ShortPressThreshold;

	/** FX Class that we will spawn when clicking */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
	TMap<UInputAction*,FCommandMapping> CommandsToInitialize;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"),Transient)
	TArray<UCQCommandBase*> Commands;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	
	virtual void SetupCommandOnInputComponent(UInputAction* InputActionToSetup, UCQCommandBase* CommandToSetup, ETriggerEvent TriggerEvent);
	virtual void SetupInputComponent() override;
	
	// To add mapping context
	virtual void BeginPlay() override;

	/** Input handlers for SetDestination action. */
	void OnInputStarted();
	void OnSetDestinationTriggered();
	void OnSetDestinationReleased();
	void OnTouchTriggered();
	void OnTouchReleased();
	void OnSetDestinationMovementStarted(const FInputActionValue& Value);
	void OnSetDestinationMovementTriggered(const FInputActionValue& Value);
	void OnSetDestinationMovementOnGoing(const FInputActionValue& Value);
	void OnSetDestinationMovementReleased(const FInputActionValue& Value);
	void OnChangeModeActionStarted(const FInputActionValue& Value);


private:
	UPROPERTY(EditAnywhere)
	EPlayerControllerMode CurrentMode { EPlayerControllerMode::ControllingSurvivor };
	FVector CachedDestination;


	FOnChangePlayerControllerMode OnChangePlayerControllerModeDelegate;
	bool bIsTouch; // Is it a touch device
	float FollowTime; // For how long it has been pressed
};


