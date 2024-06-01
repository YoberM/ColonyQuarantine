// ********************************************************************
// Copyright 2024 Maykol Mendoza. All rights reserved.
// ********************************************************************

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UENUM()
enum class EItemStatus : uint8
{
	InInventory,
	InStash,
	OnGround,
	InWorld,
	OnThrow,
	None,
};

UENUM()
enum class EActionStatus : uint8
{
	Success,
	Failed,
	None,
};

UCLASS()
class COLONYQUARANTINE_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseItem();
	
	virtual EActionStatus TryUseItem();
	virtual bool CanUseItem();
	virtual void UseItem();
	virtual bool CheckIfSameItem(ABaseItem* NewItem);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	bool bInfiniteUse { false };
	UPROPERTY(EditAnywhere)
	float UseCooldown { 1.0f };
	UPROPERTY(EditAnywhere)
	uint8 MaxStackNum { 16 };
	
	UPROPERTY(EditAnywhere)
	FString ItemName;
	UPROPERTY(EditAnywhere)
	EItemStatus ItemStatus { EItemStatus::None };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* VisualComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CollisionComponent;

};
