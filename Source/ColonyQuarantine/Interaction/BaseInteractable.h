// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseInteractable.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COLONYQUARANTINE_API UBaseInteractable : public UPrimitiveComponent
{
	GENERATED_BODY()
public:
	// Sets default values for this component's properties
	UBaseInteractable();

	virtual TArray<AActor*> GetOverlappedActors() const { return OverlappedActors; };

protected:
	// Called when the game starts	
	virtual void BeginPlay() override;
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> OverlappedActors;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* VisualComponent { nullptr };
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* CollisionComponent { nullptr };
};
