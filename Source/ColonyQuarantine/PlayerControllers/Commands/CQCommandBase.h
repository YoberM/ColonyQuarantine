// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ICommandInterface.h"
#include "CQCommandBase.generated.h"


UENUM(Blueprintable)
enum class ECommandStatus :	uint8
{
	Executing,
	Executed,
	Released,
	Failed,
};


UCLASS(Blueprintable)
class COLONYQUARANTINE_API UCQCommandBase : public UObject, public ICommandInterface
{
	GENERATED_BODY()
public:
	UCQCommandBase();
	UCQCommandBase(const FObjectInitializer& ObjectInitializer);
	UCQCommandBase(TWeakObjectPtr<class AColonyQuarantinePlayerController> NewBaseController);
	virtual void Initialize(TWeakObjectPtr<class UObject> InBaseController) override;
	virtual void ReadData(const FInputActionValue& Value);
	virtual void TryExecuteCommand(const FInputActionValue& Value);
	virtual bool CanExecuteCommand();
	virtual void ExecuteCommand(const FInputActionValue& Value) override;
	virtual bool CanReleaseCommand();
	virtual void ReleaseCommand() override;
protected:
	TWeakObjectPtr<class AColonyQuarantinePlayerController> BaseController { nullptr };
	ECommandStatus CommandStatus { ECommandStatus::Failed };

	// Debug features
	UPROPERTY(EditAnywhere)
	bool bIsDebugging {false};
	UPROPERTY(EditAnywhere)
	float DebugMessageDuration { 0.01f };

};
