// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include "Transformar.h"
#include "EncargadoEspecial1.generated.h"
UCLASS()
class OBSERVER_PATTERN_API AEncargadoEspecial1 : public AActor, public ISuscriptor, public ITransformar
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEncargadoEspecial1();

private:
	//La Torre del Reloj de este suscriptor
	UPROPERTY()
		class ATorreDelReloj* TorreDelReloj;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Estableciendo la torre del reloj para este suscriptor
	void EstablecerTorreDelReloj(ATorreDelReloj* _TorreDelReloj);

	//Llamado cuando la Editorial cambia su estado, se ejecutara la rutina del suscriptor
	void Actualizacion(class APublicador* _Publicador) override;

	//Ejecutando la rutina de este suscriptor
	void Transformar() override;

	//Cuando se destruye este suscriptor, se cancela su suscripción a la torre del reloj.
	virtual void Destroyed() override;

};
