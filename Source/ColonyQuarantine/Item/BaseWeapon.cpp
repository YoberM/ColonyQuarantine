// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseWeapon.h"

EActionStatus ABaseWeapon::TryReload()
{
	if(CanReload())
	{
		OnReload();
		return EActionStatus::Success;
	}
	return EActionStatus::Failed;
}

bool ABaseWeapon::CanReload()
{
	return true;
}

void ABaseWeapon::OnReload()
{
	// Something
}
