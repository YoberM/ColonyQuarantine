// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BaseGameMode.generated.h"

UENUM()
enum class EGamePhase : uint8
{
	PreBeginPlay,
	PostBeginPlay,
	Playing,
	Cinematic,
	Paused,
	GameOver,
};

DECLARE_DELEGATE_OneParam(FOnChangeGameState, EGamePhase)

UCLASS()
class COLONYQUARANTINE_API ABaseGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void GetAllCharacters();
	virtual void ExecuteBeforeSetGamePhase(EGamePhase NewGamePhase);
	virtual void SetGamePhase(EGamePhase NewGamePhase);
	virtual bool CheckIfCanSetGamePhase(EGamePhase NewGamePhase);
	virtual void NotifyOnChangeGamePhase(EGamePhase NewGamePhase);
	virtual TArray<AActor*> GetFoundActors() { return FoundCharacters; }

	UPROPERTY(EditAnywhere)
	bool bDebugMode { false };

protected:
	FOnChangeGameState OnChangeGameState;
	UPROPERTY(EditAnywhere)
	TArray<AActor*> FoundCharacters;
	UPROPERTY(EditAnywhere)
	EGamePhase GamePhase {EGamePhase::PreBeginPlay};
};
