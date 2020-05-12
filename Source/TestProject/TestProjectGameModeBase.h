// Copyright (c) 2020 Jimmy Lord http://www.flatheadgames.com All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TestProjectGameModeBase.generated.h"

UCLASS()
class TESTPROJECT_API ATestProjectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATestProjectGameModeBase();

	virtual void BeginPlay() override;
};
