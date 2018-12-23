// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"




void AStartGameMode::BeginPlay()
{
	// �����־
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Hello,StartGameMode"));

	// ��ʼ����Ϸ��ʼ���棨Widget��ʹ��CreateWidget��,ָ��ue4�д�����Widget�ؼ���ͼ
	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartWidgetBlueprint.BP_StartWidgetBlueprint_C'")));
	// ��ӵ��ӿ�
	StartWidget->AddToViewport();
	// ע���˺Ű�ť����¼�
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBtnOnClickedEvent);
	// ��ʼ��ע���˺Ž���
	RegisterWidget = CreateWidget<URegisterUserWidget>(GetGameInstance(), LoadClass<URegisterUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_RegisterUserWidget.BP_RegisterUserWidget_C'")));
}

// ע���˺Ű�ť����¼�
void AStartGameMode::RegisterBtnOnClickedEvent()
{
	// ��Ϸ��ʼ������ӿ��Ƴ�
	StartWidget->RemoveFromParent();
	// ���ע���˺Ž��浽�ӿ�
	RegisterWidget->AddToViewport();
}

