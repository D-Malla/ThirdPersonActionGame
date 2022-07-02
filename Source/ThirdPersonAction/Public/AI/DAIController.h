// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "DAIController.generated.h"

class UBehaviorTree;

UCLASS()
class THIRDPERSONACTION_API ADAIController : public AAIController
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category = "AI")
	UBehaviorTree* BehaviorTree;
	
	virtual void BeginPlay() override;
};
