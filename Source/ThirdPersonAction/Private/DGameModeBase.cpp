// Fill out your copyright notice in the Description page of Project Settings.


#include "DGameModeBase.h"

#include "DAttributeComponent.h"
#include "EngineUtils.h"
#include "AI/DAICharacter.h"
#include "EnvironmentQuery/EnvQueryManager.h"
#include "EnvironmentQuery/EnvQueryTypes.h"

ADGameModeBase::ADGameModeBase()
{
	SpawnTimerInterval = 2.0f;
}

void ADGameModeBase::StartPlay()
{

	Super::StartPlay();

	// Continuous timer to spawn in more bots
	// Actual amount of bots and whether its allowed to spawn determined by spawn logic later in the chain...
	GetWorldTimerManager().SetTimer(TimerHandle_SpawnBots, this, &ADGameModeBase::SpawnBotTimerElapsed, SpawnTimerInterval, true);
}

void ADGameModeBase::SpawnBotTimerElapsed()
{
	UEnvQueryInstanceBlueprintWrapper* QueryInstance = UEnvQueryManager::RunEQSQuery(this, SpawnBotQuery, this, EEnvQueryRunMode::RandomBest5Pct, nullptr);

	if (ensure(QueryInstance))
	{
		QueryInstance->GetOnQueryFinishedEvent().AddDynamic(this, &ADGameModeBase::OnQueryCompleted);
	}
}

void ADGameModeBase::OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance,
	EEnvQueryStatus::Type QueryStatus)
{
	if (QueryStatus != EEnvQueryStatus::Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn Bot EQS Query Failed!"));
		return;
	}

	int32 NrOfAliveBots = 0;
	for (TActorIterator<ADAICharacter> It(GetWorld()); It; ++It)
	{
		ADAICharacter* Bot = *It;

		UDAttributeComponent* AttributeComp = Cast<UDAttributeComponent>(Bot->GetComponentByClass(UDAttributeComponent::StaticClass()));
		if (ensure(AttributeComp) && AttributeComp->IsAlive())
		{
			NrOfAliveBots++;
		}
	}

	float MaxBotCount = 10.0f;

	if (DifficultyCurve)
	{
		MaxBotCount = DifficultyCurve->GetFloatValue(GetWorld()->TimeSeconds);
	}


	if (NrOfAliveBots >= MaxBotCount)
	{
		return;
	}
	
	TArray<FVector> Locations = QueryInstance->GetResultsAsLocations();

	if (Locations.IsValidIndex(0))
	{
		GetWorld()->SpawnActor<AActor>(MinionClass, Locations[0], FRotator::ZeroRotator);
	}
}
