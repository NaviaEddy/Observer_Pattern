// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Transformar.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTransformar : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class OBSERVER_PATTERN_API ITransformar
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	//Las funciones virtuales puras de la transformacion
	virtual void Transformar() = 0;

};
