#include "CQCameraStateFreeMode.h"

// Sets default values
ACQCameraStateFreeMode::ACQCameraStateFreeMode()
{
	// Set this empty to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACQCameraStateFreeMode::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACQCameraStateFreeMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACQCameraStateFreeMode::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
