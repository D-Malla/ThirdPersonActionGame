// Fill out your copyright notice in the Description page of Project Settings.


#include "DProjectileBase.h"

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ADProjectileBase::ADProjectileBase()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Component"));
	SphereComp->SetCollisionProfileName("Projectile");
	SphereComp->OnComponentHit.AddDynamic(this, &ADProjectileBase::OnActorHit);
	RootComponent = SphereComp;

	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Effect Component"));
	EffectComp->SetupAttachment(RootComponent);

	MoveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	MoveComp->bRotationFollowsVelocity = true;
	MoveComp->bInitialVelocityInLocalSpace = true;
	MoveComp->ProjectileGravityScale = 0.0f;
	MoveComp->InitialSpeed = 8000;

	AudioComp = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio Component"));
	AudioComp->SetupAttachment(RootComponent);
	
}

void ADProjectileBase::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	Explode();
}

// '_Implementation' from it being marked as BlueprintNativeEvent
void ADProjectileBase::Explode_Implementation()
{
	// Check to make sure we aren't already being 'destroyed'
	// Adding ensure to see if we encounter this situation at all
	if (ensure(!IsPendingKill()))
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());\

		EffectComp->DeactivateSystem();

		MoveComp->StopMovementImmediately();
		SetActorEnableCollision(false);

		Destroy();
		
		if (ImpactSound)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation(), GetActorRotation());
		}
	}
}

void ADProjectileBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
}
