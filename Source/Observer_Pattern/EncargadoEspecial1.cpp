// Fill out your copyright notice in the Description page of Project Settings.


#include "EncargadoEspecial1.h"
#include "TorreDelReloj.h"
#include "Publicador.h"

// Sets default values
AEncargadoEspecial1::AEncargadoEspecial1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEncargadoEspecial1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEncargadoEspecial1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEncargadoEspecial1::EstablecerTorreDelReloj(ATorreDelReloj* _TorreDelReloj)
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

void AEncargadoEspecial1::Actualizacion(APublicador* _Publicador)
{
	//Ejecutar la rutina
	Transformar();
}

void AEncargadoEspecial1::Transformar()
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
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, así que ENCARGADO ESPECIAL 1 sale sin desayunar"), *Tiempo));
    }
    else if (Tiempo.Equals("por mediodia"))
    {
        //Ejecuta la rutina del mediodia
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, así que la pierna izquierda del ENCARGADO ESPECIAL 1 se vuelve loco..."), *Tiempo));
    }
    else if (Tiempo.Equals("por la noche"))
    {
        //Ejecuta la rutina de la noche
        GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Es %s, por lo que el ENCARGADO ESPECIAL 1 se transforma en un animal salvaje"), *Tiempo));
    }
}

void AEncargadoEspecial1::Destroyed()
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