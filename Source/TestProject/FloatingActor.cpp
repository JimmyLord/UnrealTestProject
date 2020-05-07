// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pVisualMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Mesh") );
	m_pVisualMesh->SetupAttachment( RootComponent );

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset( TEXT("/Game/Shapes/Shape_Cube.Shape_Cube") );

	if( CubeVisualAsset.Succeeded() )
	{
		m_pVisualMesh->SetStaticMesh( CubeVisualAsset.Object );
		m_pVisualMesh->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );
	}
}

// Called when the game starts or when spawned
void AFloatingActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFloatingActor::Tick(float deltaTime)
{
	Super::Tick( deltaTime );

	float runningTime = GetGameTimeSinceCreation();
	
	float deltaHeight = (FMath::Sin(runningTime + deltaTime) - FMath::Sin(runningTime));
	FVector newLocation = GetActorLocation();
	newLocation.Z += deltaHeight * m_FloatSpeed;
	
	float deltaRotation = deltaTime * m_RotationSpeed;
	FRotator newRotation = GetActorRotation();
	newRotation.Yaw += deltaRotation;
	
	SetActorLocationAndRotation( newLocation, newRotation );
}

