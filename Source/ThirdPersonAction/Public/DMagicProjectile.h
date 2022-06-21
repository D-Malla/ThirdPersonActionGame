#pragma once

#include "CoreMinimal.h"
#include "DProjectileBase.h"
#include "GameFramework/Actor.h"
#include "DMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class THIRDPERSONACTION_API ADMagicProjectile : public ADProjectileBase // Re-parented from AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADMagicProjectile();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float DamageAmount;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
