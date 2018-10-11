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
}

