// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DGameplayInterface.h"
#include "DItemChest.generated.h"

UCLASS()
class THIRDPERSONACTION_API ADItemChest : public AActor, public IDGameplayInterface // <-- Must add interface here to use.
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float TargetPitch;

	// _Implementation is not appened because of GamePlayInterface. It is because we used the "BlueprintNative" specifier for Interact(APawn* InstigatorPawn) in GamePlayInterface
	void Interact_Implementation(APawn* InstigatorPawn); 

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* LidMesh;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ADItemChest();
};
