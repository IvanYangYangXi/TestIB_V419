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
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_PlayGame")));
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	return true;
}
