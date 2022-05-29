#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DExplosiveBarrel.generated.h"

UCLASS()
class THIRDPERSONACTION_API ADExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADExplosiveBarrel();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
