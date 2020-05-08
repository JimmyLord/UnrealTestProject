// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "TestCharacter.generated.h"

UCLASS()
class TESTPROJECT_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties.
	ATestCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* m_pCameraArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	UCameraComponent* m_pCamera;

	void MoveForward(float amount);
	void MoveRight(float amount);

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input.
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
