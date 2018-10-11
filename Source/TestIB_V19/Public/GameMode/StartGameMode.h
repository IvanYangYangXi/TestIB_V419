// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "StartUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTIB_V19_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	// 定义开始界面
	UPROPERTY()
		UStartUserWidget* StartWidget;

public:

	virtual void BeginPlay() override;
	
	
};
