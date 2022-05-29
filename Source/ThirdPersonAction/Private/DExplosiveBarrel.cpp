// Fill out your copyright notice in the Description page of Project Settings.


#include "DExplosiveBarrel.h"

// Sets default values
ADExplosiveBarrel::ADExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ADExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}
