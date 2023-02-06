// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Publicador.h"
#include "TorreDelReloj.generated.h"

/**
 * 
 */
UCLASS()
class OBSERVER_PATTERN_API ATorreDelReloj : public APublicador
{
	GENERATED_BODY()

public:
    ATorreDelReloj();

private:
	//La hora actual de esta Torre del Reloj
	FString Tiempo;

public:
    //Llamada cuando la hora de esta TorredelReloj ha cambiado
    void CambioDeLaHora();

    //Ajuste la hora de esta TorredelReloj
    void FijarLaHoraDelDia(FString _Tiempo);

    //Devuelve el tiempo de la TorreDelReloj
    FORCEINLINE FString ObtenerTiempo() { return Tiempo; };

	
};
