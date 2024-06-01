// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseInteractable.h"

UBaseInteractable::UBaseInteractable()
{
	PrimaryComponentTick.bCanEverTick = true;
	VisualComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Component"));
	VisualComponent->SetupAttachment(this);
	VisualComponent->SetCollisionProfileName(TEXT("NoCollision"));

	CollisionComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision Component"));
	CollisionComponent->SetupAttachment(this);
	CollisionComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &UBaseInteractable::OnOverlapBegin);
	CollisionComponent->OnComponentEndOverlap.AddDynamic(this, &UBaseInteractable::OnOverlapEnd);
	UE_LOG(LogTemp, Warning, TEXT("UBaseInteractable created: %s"), *GetName());
}

void UBaseInteractable::BeginPlay()
{
	Super::BeginPlay();
}

void UBaseInteractable::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap Begin"));
}

void UBaseInteractable::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
}


