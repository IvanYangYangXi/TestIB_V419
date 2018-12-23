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
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));
	StartBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_PlayGame")));
	LoginBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Login")));
	QuitBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Quit")));

	// 按钮点击事件
	QuitBtn->OnClicked.AddDynamic(this, &UStartUserWidget::QuitBtnOnClickedEvent);

	return true;
}

// 退出按钮点击事件
void UStartUserWidget::QuitBtnOnClickedEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("QuitBtn On Clicked..."));
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit);
}
