// Fill out your copyright notice in the Description page of Project Settings.


#include "DAttributeComponent.h"

// Sets default values for this component's properties
UDAttributeComponent::UDAttributeComponent()
{
	HealthMax = 100.0f;
	Health = HealthMax;
}

bool UDAttributeComponent::IsAlive() const
{
	return Health > 0.0f;
}

bool UDAttributeComponent::IsFullHealth() const
{
	return Health == HealthMax;
}

float UDAttributeComponent::GetHealthMax() const
{
	return HealthMax;
}

bool UDAttributeComponent::ApplyHealthChange(float Delta)
{
	float OldHealth = Health;
	
	Health = FMath::Clamp(Health + Delta, 0.0f, HealthMax);

	float ActualDelta = Health - OldHealth;
	
	OnHealthChanged.Broadcast(nullptr, this, Health, ActualDelta);

	return ActualDelta != 0;
}
