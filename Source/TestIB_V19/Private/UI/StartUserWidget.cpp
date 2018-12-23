// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"



// ��ʼ���ؼ�
bool UStartUserWidget::Initialize()
{
	// ��ʼ����ť����UMG�ؼ���ʼ��֮ǰ������ťδ��ʼ���򷵻ؼ�
	if (!Super::Initialize())
	{
		return false;
	}
	
	// ��ʼ����ť
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_PlayGame")));
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	// ��ť����¼�
	QuitBtn->OnClicked.AddDynamic(this, &UStartUserWidget::QuitBtnOnClickedEvent);

	return true;
}

// �˳���ť����¼�
void UStartUserWidget::QuitBtnOnClickedEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("QuitBtn On Clicked..."));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit);
}
