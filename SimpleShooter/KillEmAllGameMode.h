// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGamemodeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGamemodeBase
{
	GENERATED_BODY()

public:
	virtual void PawnKilled(APawn* PawnKilled) override;

private:
	void EndGame(bool bIsPlayerWinner);
	
};
