#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UDInteractionComponent;
class UAnimMontage;
class UDAttributeComponent;
class UParticleSystem;

UCLASS()
class THIRDPERSONACTION_API ADCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADCharacter();
		
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// VisibleAnywhere = read-only, still useful to view in-editor and enforce a convention
	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName TimeToHitParams;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName HandSocketName;
	
	// Choose Projectile in BP_PlayerCharacter/Unreal Editor
	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> BlackHoleProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TSubclassOf<AActor> DashProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	/* Particle System played during attack animation */
	UPROPERTY(EditAnywhere, Category = "Attack")
	UParticleSystem* CastingEffect;

	FTimerHandle TimerHandle_PrimaryAttack;
	FTimerHandle TimerHandle_BlackHoleAttack;
	FTimerHandle TimerHandle_Dash;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	float AttackAnimDelay;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	UDInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UDAttributeComponent* AttributeComp;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void PrimaryAttack();

	void PrimaryAttack_TimeElapsed();

	void BlackHoleAttack();

	void BlackHoleAttack_TimeElapsed();

	void Dash();

	void Dash_TimeElapsed();

	void StartAttackEffects();

	// Re-use spawn logic between attacks
	void SpawnProjectile(TSubclassOf<AActor> ClassToSpawn);

	void PrimaryInteract();

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, UDAttributeComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;
};
