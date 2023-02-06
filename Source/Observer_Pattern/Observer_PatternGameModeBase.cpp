// Copyright Epic Games, Inc. All Rights Reserved.


#include "Observer_PatternGameModeBase.h"
#include "TorreDelReloj.h"
#include "PersonaEspecial1.h"
#include "JefeEspecial1.h"
#include "EncargadoEspecial1.h"

AObserver_PatternGameModeBase::AObserver_PatternGameModeBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AObserver_PatternGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//Engendrar la TorreDelReloj
	ATorreDelReloj* TorreDelReloj = GetWorld()->SpawnActor<ATorreDelReloj>(ATorreDelReloj::StaticClass());

	//Engendra el primer suscriptor y fija su torre del reloj.
	APersonaEspecial1 *PE1 = GetWorld()->SpawnActor<APersonaEspecial1>(APersonaEspecial1::StaticClass());
	PE1->EstablecerTorreDelReloj(TorreDelReloj);

	//Engendra el segundo suscriptor y fija su torre del reloj.
	AJefeEspecial1* JE1 = GetWorld()->SpawnActor<AJefeEspecial1>(AJefeEspecial1::StaticClass());
	JE1->EstablecerTorreDelReloj(TorreDelReloj);

	//Engendra el tercer suscriptor y fija su torre del reloj.
	AEncargadoEspecial1* EE1 = GetWorld()->SpawnActor<AEncargadoEspecial1>(AEncargadoEspecial1::StaticClass());
	EE1->EstablecerTorreDelReloj(TorreDelReloj);

	//Cambiar la hora de la Torre del Reloj, para que los abonados puedan ejecutar su propia rutina
	TorreDelReloj->FijarLaHoraDelDia("por el dia");
	TorreDelReloj->FijarLaHoraDelDia("por mediodia");
	TorreDelReloj->FijarLaHoraDelDia("por la noche");

}

void AObserver_PatternGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
