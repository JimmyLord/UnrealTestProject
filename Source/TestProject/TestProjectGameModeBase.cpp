// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#include "TestProjectGameModeBase.h"

ATestProjectGameModeBase::ATestProjectGameModeBase()
{
	//PrimaryActorTick.bCanEverTick = true;
}

void ATestProjectGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	//GEngine->AddOnScreenDebugMessage( -1, 1.0f, FColor::Green, FString::Printf( TEXT("GameMode Begin") ) );
}