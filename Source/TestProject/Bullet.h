// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

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

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult);
};
