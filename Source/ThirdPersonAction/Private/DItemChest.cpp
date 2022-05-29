// Fill out your copyright notice in the Description page of Project Settings.


#include "DItemChest.h"

// Sets default values
ADItemChest::ADItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	RootComponent = BaseMesh;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lid Mesh"));
	LidMesh->SetupAttachment(BaseMesh);

	TargetPitch = 110.f;
}

// Called when the game starts or when spawned
void ADItemChest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADItemChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADItemChest::Interact_Implementation(APawn* InstigatorPawn)
{
	LidMesh->SetRelativeRotation(FRotator(TargetPitch, 0, 0));
}