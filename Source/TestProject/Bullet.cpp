// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#include "Bullet.h"

// Sets default values.
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Mesh") );
	m_pMesh->SetupAttachment( RootComponent );

	ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT("/Game/Shapes/Shape_Cone.Shape_Cone") );

	if( mesh.Succeeded() )
	{
		m_pMesh->SetStaticMesh( mesh.Object );
		m_pMesh->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );
	}
}

// Called when the game starts or when spawned.
void ABullet::BeginPlay()
{
	Super::BeginPlay();

	m_pMesh->OnComponentBeginOverlap.AddDynamic( this, &ABullet::OnBeginOverlap );
	m_pMesh->OnComponentHit.AddDynamic( this, &ABullet::OnHit );
}

// Called every frame.
void ABullet::Tick(float deltaTime)
{
	Super::Tick( deltaTime );

	// Move the bullet.
	FVector pos = GetActorLocation();
	pos += m_Direction * m_Speed * deltaTime;

	// Set the new position and do a sweep to the target to find any collisions, this will generate calls to OnHit.
	SetActorLocation( pos, true );

	// Remove bullet if it's lived too long.
	m_Lifetime -= deltaTime;
	if( m_Lifetime <= 0 )
	{
		Destroy();
	}
}

void ABullet::OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult)
{
	//GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Bullet was overlapped!") ) );
}

void ABullet::OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult)
{
	GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("Bullet was hit!") ) );

	// We hit something, remove from world.
	Destroy();
}
