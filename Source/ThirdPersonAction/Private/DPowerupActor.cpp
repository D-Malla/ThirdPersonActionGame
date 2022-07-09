// Fill out your copyright notice in the Description page of Project Settings.


#include "DPowerupActor.h"
#include "Components/SphereComponent.h"


ADPowerupActor::ADPowerupActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Powerup");
	RootComponent = SphereComp;

	RespawnTime = 10.0f;
}


void ADPowerupActor::Interact_Implementation(APawn* InstigatorPawn)
{
	// logic in derived classes...
}


void ADPowerupActor::ShowPowerup()
{
	SetPowerupState(true);
}


void ADPowerupActor::HideAndCooldownPowerup()
{
	SetPowerupState(false);

	FTimerHandle TimerHandle_RespawnTimer;
	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ADPowerupActor::ShowPowerup, RespawnTime);
}

void ADPowerupActor::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
}