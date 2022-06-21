// Fill out your copyright notice in the Description page of Project Settings.


#include "DAttributeComponent.h"

// Sets default values for this component's properties
UDAttributeComponent::UDAttributeComponent()
{
	Health = 100.0f;
}

bool UDAttributeComponent::ApplyHealthChange(float Delta)
{
	Health += Delta;

	OnHealthChanged.Broadcast(nullptr, this, Health, Delta);

	return true;
}