// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ABullet;
class AActor;
class UPrimitiveComponent;

UCLASS()
class TESTPROJECT_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties.
	ATestCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* m_pCameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* m_pCamera;

	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
	TSubclassOf<ABullet> m_BulletActor;

	void MoveForward(float amount);
	void MoveRight(float amount);
	void Shoot();
	void SpawnBullet(FVector pos, FRotator rot);

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* ourComp, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool fromSweep, const FHitResult& sweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* hitComp, AActor* otherActor, UPrimitiveComponent* otherComp, FVector normalImpulse, const FHitResult& hitResult);

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	// Called every frame.
	virtual void Tick(float deltaTime) override;

	// Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
