#include "DMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "DAttributeComponent.h"
#include "Kismet/GameplayStatics.h"

ADMagicProjectile::ADMagicProjectile()
{
	SphereComp->SetSphereRadius(20.0f);
	SphereComp->OnComponentBeginOverlap.AddDynamic(this, &ADMagicProjectile::OnActorOverlap);

	DamageAmount = 20.0f;
}


void ADMagicProjectile::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != GetInstigator())
	{
		UDAttributeComponent* AttributeComp = Cast<UDAttributeComponent>(OtherActor->GetComponentByClass(UDAttributeComponent::StaticClass()));
		if (AttributeComp)
		{
			// minus in front of DamageAmount to apply the change as damage, not healing
			AttributeComp->ApplyHealthChange(-DamageAmount);
			
			// Only explode when we hit something valid
			Explode();

		}
	}
}