// Fill out your copyright notice in the Description page of Project Settings.


#include "TorreDelReloj.h"

ATorreDelReloj::ATorreDelReloj()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATorreDelReloj::CambioDeLaHora()
{
	//Cuando la hora ha cambiado, esta TorredelReloj(que es un Publicador) notifica a todos los abonados que la hora ha cambiado
	NotificarASuscriptores();
}

void ATorreDelReloj::FijarLaHoraDelDia(FString _Tiempo)
{
	//Ajustar la hora utilizando el parámetro pasado y avisar de que ha cambiado
	Tiempo = _Tiempo;
	CambioDeLaHora();

}

