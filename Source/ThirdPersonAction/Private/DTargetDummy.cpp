// Fill out your copyright notice in the Description page of Project Settings.


#include "DTargetDummy.h"

// Sets default values
ADTargetDummy::ADTargetDummy()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	RootComponent = MeshComp;

	AttributeComp = CreateDefaultSubobject<UDAttributeComponent>(TEXT("Attribute Component"));
	// Trigger when health is changed (damage/healing)
	AttributeComp->OnHealthChanged.AddDynamic(this,	&ADTargetDummy::OnHealthChanged);

}

void ADTargetDummy::OnHealthChanged(AActor* InstigatorActor, UDAttributeComponent* OwningComp, float NewHealth,
	float Delta)
{
	if (Delta < 0.f)
	{
		MeshComp->SetScalarParameterValueOnMaterials(TEXT("TimeToHit"), GetWorld()->TimeSeconds);
	}
}