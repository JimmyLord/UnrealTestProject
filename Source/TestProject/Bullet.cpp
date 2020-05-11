// Fill out your copyright notice in the Description page of Project Settings.

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
	
}

// Called every frame.
void ABullet::Tick(float deltaTime)
{
	Super::Tick( deltaTime );

	// Move the bullet.
	FVector pos = GetActorLocation();
	pos += m_Direction * m_Speed * deltaTime;

	SetActorLocation( pos );

	// Remove bullet if it's lived too long.
	m_Lifetime -= deltaTime;
	if( m_Lifetime <= 0 )
	{
		Destroy();
	}
}

