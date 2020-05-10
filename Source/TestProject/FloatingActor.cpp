// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingActor.h"

// Sets default values
AFloatingActor::AFloatingActor()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_pMesh = CreateDefaultSubobject<UStaticMeshComponent>( TEXT("Mesh") );
	m_pMesh->SetupAttachment( RootComponent );

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mesh( TEXT("/Game/Shapes/Shape_Cube.Shape_Cube") );

	if( mesh.Succeeded() )
	{
		m_pMesh->SetStaticMesh( mesh.Object );
		m_pMesh->SetRelativeLocation( FVector(0.0f, 0.0f, 0.0f) );
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

