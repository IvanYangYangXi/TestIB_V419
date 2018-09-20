// Fill out your copyright notice in the Description page of Project Settings.

#include "StartUserWidget.h"



// 初始化控件
bool UStartUserWidget::Initialize()
{
	// 初始化按钮须在UMG控件初始化之前，若按钮未初始化则返回假
	if (!Super::Initialize())
	{
		return false;
	}
	
	// 初始化按钮
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_PlayGame")));
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	return true;
}
