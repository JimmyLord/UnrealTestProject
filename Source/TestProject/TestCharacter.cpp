// Fill out your copyright notice in the Description page of Project Settings.

#include "TestCharacter.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize( 10.0f, 10.0f );

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->RotationRate = FRotator( 0, 100.0f, 0 );
	GetCharacterMovement()->JumpZVelocity = 100.0f;
	GetCharacterMovement()->AirControl = 0.5f;

	m_pCameraArm = CreateDefaultSubobject<USpringArmComponent>( TEXT("CameraArm") );
	m_pCameraArm->SetupAttachment( RootComponent );
	m_pCameraArm->TargetArmLength = 400.0f;
	m_pCameraArm->bUsePawnControlRotation = true;

	m_pCamera = CreateDefaultSubobject<UCameraComponent>( TEXT("Camera") );
	m_pCamera->SetupAttachment( m_pCameraArm, USpringArmComponent::SocketName );
	m_pCamera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned.
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame.
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input.
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis( "Turn", this, &APawn::AddControllerYawInput );
	PlayerInputComponent->BindAxis( "LookUp", this, &APawn::AddControllerPitchInput );

	PlayerInputComponent->BindAxis( "MoveForward", this, &ATestCharacter::MoveForward );
	PlayerInputComponent->BindAxis( "MoveRight", this, &ATestCharacter::MoveRight );
}

void ATestCharacter::MoveForward(float amount)
{
	float yaw = Controller->GetControlRotation().Yaw * PI / 180.0f;

	FVector dir( cos(yaw), sin(yaw), 0 );

	//GEngine->AddOnScreenDebugMessage( 100, 5.f, FColor::Green, FString::Printf( TEXT("Yaw: %f"), yaw ) );
	//GEngine->AddOnScreenDebugMessage( 101, 5.f, FColor::Green, FString::Printf( TEXT("Dir: %f,%f"), dir.X, dir.Y ) );

	AddMovementInput( dir, amount );
}

void ATestCharacter::MoveRight(float amount)
{
	float yaw = (Controller->GetControlRotation().Yaw + 90) * PI / 180.0f;

	FVector dir( cos(yaw), sin(yaw), 0 );

	AddMovementInput( dir, amount );
}

