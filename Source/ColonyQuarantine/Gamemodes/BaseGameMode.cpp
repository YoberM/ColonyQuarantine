// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************

#include "BaseGameMode.h"

#include "ColonyQuarantine/Characters/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"

void ABaseGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetAllCharacters();
	SetGamePhase(EGamePhase::PostBeginPlay);
}

void ABaseGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetGamePhase(EGamePhase::Playing);
}

void ABaseGameMode::GetAllCharacters()
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseCharacter::StaticClass(), FoundCharacters);
}

void ABaseGameMode::ExecuteBeforeSetGamePhase(EGamePhase NewGamePhase)
{
	// Example
	switch (GamePhase)
	{
	case EGamePhase::PreBeginPlay:
		{
			// Do something
		}
		break;
	case EGamePhase::PostBeginPlay:
		break;
	case EGamePhase::Playing:
		break;
	case EGamePhase::Cinematic:
		break;
	case EGamePhase::Paused:
		break;
	case EGamePhase::GameOver:
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("ABaseGameMode::ExecuteBeforeSetGame GamePhase CRITICAL FAIL"));
		break;
	}



}

bool ABaseGameMode::CheckIfCanSetGamePhase(EGamePhase NewGamePhase)
{
	// Example of use
	switch (GamePhase)
	{
	case EGamePhase::PreBeginPlay:
		{
			// Check Something
		}
		break;
	case EGamePhase::PostBeginPlay:
		break;
	case EGamePhase::Playing:
		break;
	case EGamePhase::Cinematic:
		break;
	case EGamePhase::Paused:
		break;
	case EGamePhase::GameOver:
		break;
	default:
		UE_LOG(LogTemp, Warning, TEXT("ABaseGameMode::CheckIfCanSetGameState GamePhase CRITICAL FAIL"));
		break;
	}
	return true;
}

void ABaseGameMode::NotifyOnChangeGamePhase(EGamePhase NewGamePhase)
{
	OnChangeGameState.ExecuteIfBound(NewGamePhase);
}

void ABaseGameMode::SetGamePhase(EGamePhase NewGamePhase)
{
	if(CheckIfCanSetGamePhase(NewGamePhase))
	{
		ExecuteBeforeSetGamePhase(NewGamePhase);
		NotifyOnChangeGamePhase(NewGamePhase);
		GamePhase = NewGamePhase;
	}
}

