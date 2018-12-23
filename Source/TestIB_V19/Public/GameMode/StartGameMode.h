// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "StartUserWidget.h"
#include "RegisterUserWidget.h"
#include "StartGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TESTIB_V19_API AStartGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	// ���忪ʼ����
	UPROPERTY()
		UStartUserWidget* StartWidget;
	// ����ע�����
	UPROPERTY()
		URegisterUserWidget* RegisterWidget;

public:

	virtual void BeginPlay() override;
	// ע���˺Ű�ť����¼�
	UFUNCTION()
		void RegisterBtnOnClickedEvent();
	
};
