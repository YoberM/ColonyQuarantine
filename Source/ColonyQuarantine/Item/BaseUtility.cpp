// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUtility.h"

EActionStatus ABaseUtility::TryConsume()
{
	if(CanConsume())
	{
		OnConsume();
		return EActionStatus::Success;
	}
	return EActionStatus::Failed;
}

bool ABaseUtility::CanConsume()
{
	return true;
}

void ABaseUtility::OnConsume()
{
}
