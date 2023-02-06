// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Suscriptor.h"
#include "Publicador.generated.h"

UCLASS()
class OBSERVER_PATTERN_API APublicador : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APublicador();

private:
	//Los suscriptores de esta editorial y lo inicializamos
	UPROPERTY()
		TArray<AActor*>Suscriptores = TArray<AActor*>();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//Añadir el suscriptor a la lista
	virtual void Suscribirse(AActor* _Suscriptor);

	//Eliminar de la lista el suscriptor pasado
	virtual void CancelarSuscripcion(AActor* _RemoverSuscriptor);

	//Notificar a todos los suscriptores que algo ha cambiado
	virtual void NotificarASuscriptores();

};
