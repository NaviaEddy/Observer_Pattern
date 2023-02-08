// Fill out your copyright notice in the Description page of Project Settings.


#include "JefeEspecial1.h"
#include "TorreDelReloj.h"
#include "Publicador.h"

// Sets default values
AJefeEspecial1::AJefeEspecial1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AJefeEspecial1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJefeEspecial1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AJefeEspecial1::EstablecerTorreDelReloj(ATorreDelReloj* _TorreDelReloj)
{
    //Registrar error si la Torre del Reloj pasada es NULL
    if (!_TorreDelReloj) {
        UE_LOG(LogTemp, Error, TEXT("EstablecerTorreDelReloj(): _ToreeDelReloj es NULL, asegurese de que este inicializado."));
        return;
    }

    //Establecer la TorreDelReloj y Suscribirse a ella
    TorreDelReloj = _TorreDelReloj;
    TorreDelReloj->Suscribirse(this);
}

void AJefeEspecial1::Actualizacion(APublicador* _Publicador)
{
	//Ejecutar la rutina
	Transformar();
}

void AJefeEspecial1::Transformar()
{
    //Log Error si su Torre del Reloj es NULL
    if (!TorreDelReloj) {
        UE_LOG(LogTemp, Error, TEXT("Transformar(): TorreDelReloj es NULL, asegurese de que este inicializada."));
        return;
    }

    //Obtener la hora actual de la TorreDelReloj
    FString Tiempo = TorreDelReloj->ObtenerTiempo();

    if (Tiempo.Equals("por el dia"))
    {
        //Ejecuta la rutina del dia
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, as� que JEFE ESPECIAL 1 hace un desayuno frances"), *Tiempo));
    }
    else if (Tiempo.Equals("por mediodia"))
    {
        //Ejecuta la rutina del mediodia
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, as� que la mano izquierda del JEFE ESPECIAL 1 empieza a caerse..."), *Tiempo));
    }
    else if (Tiempo.Equals("por la noche"))
    {
        //Ejecuta la rutina de la noche
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, por lo que JEFE ESPECIAL 1 se transforma en un hombre lobo"), *Tiempo));
    }
}

void AJefeEspecial1::Destroyed()
{
    Super::Destroyed();

    //Log Error si su TorredelReloj es NULL
    if (!TorreDelReloj) {
        UE_LOG(LogTemp, Error, TEXT("Destroyed(): TorreDelReloj es NULL, asegurese de que este inicializado."));
        return;
    }

    //Darse de baja de la Torre del Reloj si se destruye
    TorreDelReloj->CancelarSuscripcion(this);
}