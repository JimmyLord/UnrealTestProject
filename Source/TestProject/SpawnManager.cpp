// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#include "SpawnManager.h"
#include "Engine/TriggerBox.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values.
ASpawnManager::ASpawnManager()
{
 	// Set this actor to NOT call Tick() every frame.
	//PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned.
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("ASpawnManager::BeginPlay") ) );

	// Set a recurring 1 second timer, spawns will happen every second at most.
	GetWorldTimerManager().SetTimer( m_TimerHandle, this, &ASpawnManager::TimerTick, 1.0f, true );
}

void ASpawnManager::TimerTick()
{
	GEngine->AddOnScreenDebugMessage( -1, 0.6f, FColor::Green, FString::Printf( TEXT("ASpawnManager::TimerTick %d"), m_SpawnAreas.Num() ) );

	if( m_SpawnAreas.Num() > 0 )
	{
		if( m_SpawnAreas[0] == nullptr )
		{
			GEngine->AddOnScreenDebugMessage( -1, 0.6f, FColor::Green, FString::Printf( TEXT("Spawn area is null") ) );
			return;
		}

		GEngine->AddOnScreenDebugMessage( -1, 0.6f, FColor::Green, FString::Printf( TEXT("%s"), *m_SpawnAreas[0]->GetName() ) );

		FVector origin;
		FVector extent;
		m_SpawnAreas[0]->GetActorBounds( false, origin, extent, false );

		//FVector pos(0,0,0);
		FVector pos = UKismetMathLibrary::RandomPointInBoundingBox( origin, extent );
		pos.Z = 0;
		FRotator rot(0,0,0);

		// Spawn an enemy.
		FActorSpawnParameters params;
		AEnemy* pEnemy = GetWorld()->SpawnActor<AEnemy>( m_EnemyActor, pos, rot, params );
	}
}
