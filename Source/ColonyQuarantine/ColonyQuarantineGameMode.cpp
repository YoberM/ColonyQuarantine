// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************
#include "ColonyQuarantineGameMode.h"
#include "ColonyQuarantinePlayerController.h"
#include "Characters/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AColonyQuarantineGameMode::AColonyQuarantineGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AColonyQuarantinePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	PrimaryActorTick.bCanEverTick = true;
}

void AColonyQuarantineGameMode::BeginPlay()
{
	Super::BeginPlay();
}
