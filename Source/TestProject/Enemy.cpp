// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemy.h"

// Sets default values.
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Mesh") );
	m_pMesh->SetupAttachment( RootComponent );

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT("/Game/Shapes/Shape_Cube.Shape_Cube") );

	if( mesh.Succeeded() )
	{
		m_pMesh->SetStaticMesh( mesh.Object );
		m_pMesh->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );
		//m_pMesh->SetMaterial();
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

	// Move the bullet.
	FVector pos = GetActorLocation();
	pos += m_Direction * m_Speed * deltaTime;

	SetActorLocation( pos );
}

void AEnemy::OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{
	GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Enemy was overlapped!") ) );
}

void AEnemy::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult)
{
	GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Enemy was hit!") ) );
}
