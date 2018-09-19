// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "StartUserWidget.generated.h"


/**
 * 游戏开始界面
 */
UCLASS()
class TESTIB_V19_API UStartUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Play Button
	UPROPERTY()
		UButton* StartBtn;
	// Login Button
	UPROPERTY()
		UButton* LoginBtn;
	// Quit Button
	UPROPERTY()
		UButton* QuitBtn;

public:
	// 初始化控件
	virtual bool Initialize() override;
	
	
};
