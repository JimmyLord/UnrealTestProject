// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

UCLASS()
class TESTPROJECT_API AEnemy : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AEnemy();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* m_pMesh;

	FVector m_Direction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enemy Properties")
	float m_Speed = 100.0f;

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float deltaTime) override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult);
};
