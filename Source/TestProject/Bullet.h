// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class TESTPROJECT_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	ABullet();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* m_pMesh;

	FVector m_Direction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bullet Properties")
	float m_Speed = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Bullet Properties")
	float m_Lifetime = 2.0f;

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	// Called every frame.
	virtual void Tick(float deltaTime) override;

};
