// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"




void AStartGameMode::BeginPlay()
{
	// 输出日志
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Hello,StartGameMode"));

	// 初始化游戏开始界面（Widget类使用CreateWidget）,指向ue4中创建的Widget控件蓝图
	StartWidget = CreateWidget<UStartUserWidget>(GetGameInstance(), LoadClass<UStartUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_StartWidgetBlueprint.BP_StartWidgetBlueprint_C'")));
	// 添加到视口
	StartWidget->AddToViewport();
	// 注册账号按钮点击事件
	StartWidget->RegisterBtn->OnClicked.AddDynamic(this, &AStartGameMode::RegisterBtnOnClickedEvent);
	// 初始化注册账号界面
	RegisterWidget = CreateWidget<URegisterUserWidget>(GetGameInstance(), LoadClass<URegisterUserWidget>(this, TEXT("WidgetBlueprint'/Game/UI/BP_RegisterUserWidget.BP_RegisterUserWidget_C'")));
}

// 注册账号按钮点击事件
void AStartGameMode::RegisterBtnOnClickedEvent()
{
	// 游戏开始界面从视口移除
	StartWidget->RemoveFromParent();
	// 添加注册账号界面到视口
	RegisterWidget->AddToViewport();
}

