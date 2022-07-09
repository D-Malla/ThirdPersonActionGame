// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DPowerupActor.h"
#include "DPowerup_HealthPotion.generated.h"

class UStaticMeshComponent;

UCLASS()
class THIRDPERSONACTION_API ADPowerup_HealthPotion : public ADPowerupActor
{
	GENERATED_BODY()
		
protected:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	// float healt amount?

	public:

	void Interact_Implementation(APawn* InstigatorPawn) override;

	ADPowerup_HealthPotion();
};
