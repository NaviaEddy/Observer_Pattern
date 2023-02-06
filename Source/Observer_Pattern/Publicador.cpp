// Fill out your copyright notice in the Description page of Project Settings.


#include "Publicador.h"

// Sets default values
APublicador::APublicador()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APublicador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APublicador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APublicador::Suscribirse(AActor* _Suscriptor)
{
	//Añadir el suscriptor pasado
	Suscriptores.Add(_Suscriptor);
}

void APublicador::CancelarSuscripcion(AActor* _RemoverSuscriptor)
{
	//Remover el suscriptor pasado
	Suscriptores.Remove(_RemoverSuscriptor);

}

void APublicador::NotificarASuscriptores()
{
    //Bucle para cada suscriptor
    for (AActor* Actor : Suscriptores)
    {
        //Asignar cada uno de ellos a un suscriptor concreto
        ISuscriptor* Sus = Cast<ISuscriptor>(Actor);

        if (Sus)
        {
            //Notifique a cada uno de ellos que algo ha cambiado, para que puedan ejecutar su propia rutina
            Sus->Actualizacion(this);
        }
    }
}

