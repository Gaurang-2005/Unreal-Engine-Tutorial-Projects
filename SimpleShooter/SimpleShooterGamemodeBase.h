// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SimpleShooterGamemodeBase.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API ASimpleShooterGamemodeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void PawnKilled(APawn* PawnKilled);
};
