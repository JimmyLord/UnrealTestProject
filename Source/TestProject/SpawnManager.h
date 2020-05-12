// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

class AEnemy;
class ATriggerBox;

UCLASS()
class TESTPROJECT_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
protected:
	FTimerHandle m_TimerHandle;

public:
	UPROPERTY(EditAnywhere, Category = "Spawns")
		TSubclassOf<AEnemy> m_EnemyActor;

	UPROPERTY(EditInstanceOnly, Category = "Spawns")
		TArray<ATriggerBox*> m_SpawnAreas;

public:	
	// Sets default values for this actor's properties.
	ASpawnManager();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	

	void TimerTick();
};
