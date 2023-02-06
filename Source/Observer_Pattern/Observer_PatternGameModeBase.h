// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Observer_PatternGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class OBSERVER_PATTERN_API AObserver_PatternGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
    // Sets default values for this actor's properties
    AObserver_PatternGameModeBase();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

};
