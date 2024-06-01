// Fill out your copyright notice in the Description page of Project Settings.


#include "CQGameMode.h"
#include "ColonyQuarantine/Characters/CQCharacterSurvivor.h"
#include "ColonyQuarantine/Characters/CQCharacterZombie.h"

void ACQGameMode::GetAllCharacters()
{
	Super::GetAllCharacters();
	for (int i = 0; i < FoundCharacters.Num(); ++i)
	{
		Survivors.Reset();
		Zombies.Reset();
		if(ACQCharacterSurvivor* Survivor = Cast<ACQCharacterSurvivor>(FoundCharacters[i]))
		{
			Survivors.Add(Survivor);
		}
		else if(ACQCharacterZombie* Zombie = Cast<ACQCharacterZombie>(FoundCharacters[i]))
		{
			Zombies.Add(Zombie);
		}
	}
}
