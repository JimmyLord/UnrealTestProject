// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#include "Enemy.h"
#include "Bullet.h"

// Sets default values.
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Mesh") );
	RootComponent = m_pMesh;

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT("/Game/Shapes/Shape_Cube.Shape_Cube") );
	if( mesh.Succeeded() )
	{
		UMaterial* pMaterial = nullptr;
		if( rand()%2 == 0 )
		{
			pMaterial = Cast<UMaterial>( StaticLoadObject( UMaterial::StaticClass(), NULL, TEXT("Material'/Game/Materials/Blue.Blue'") ) );
			m_Shootable = true;
		}
		else
		{
			pMaterial = Cast<UMaterial>( StaticLoadObject( UMaterial::StaticClass(), NULL, TEXT("Material'/Game/Materials/Green.Green'") ) );
			m_Shootable = false;
		}

		m_pMesh->SetStaticMesh( mesh.Object );
		m_pMesh->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );
		m_pMesh->SetRelativeScale3D( FVector(0.2f) );
		m_pMesh->SetSimulatePhysics( true );
		m_pMesh->SetMaterial( 0, pMaterial );
	}
}

// Called when the game starts or when spawned.
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	m_pMesh->OnComponentBeginOverlap.AddDynamic( this, &AEnemy::OnBeginOverlap );
	m_pMesh->OnComponentHit.AddDynamic( this, &AEnemy::OnHit );
}

// Called every frame.
void AEnemy::Tick(float deltaTime)
{
	Super::Tick( deltaTime );

	FVector pos = GetActorLocation();
	FVector playerPos = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();

	// Move the enemy towards the player.
	m_Direction = playerPos - pos;
	pos += m_Direction * m_Speed * deltaTime;

	// If the enemy falls off the world, destroy it.
	if( pos.Z < -10 )
		Destroy();

	SetActorLocation( pos );
}

void AEnemy::OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{
	//GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Enemy was overlapped!") ) );
}

void AEnemy::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult)
{
	GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Enemy was hit!") ) );

	// Destroy the enemy if it's hit by a bullet.
	if( otherActor->IsA<ABullet>() && m_Shootable )
	{
		Destroy();
	}
}
