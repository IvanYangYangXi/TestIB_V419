// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "RegisterUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class TESTIB_V19_API URegisterUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// 返回按钮
	UPROPERTY()
		UButton* BackBtn;
	// 用户名输入框
	UPROPERTY()
		UEditableTextBox* UserNameInput;
	// 密码输入框
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	// 注册按钮
	UPROPERTY()
		UButton* RegisterBtn;

public:
	// 初始化控件
	virtual bool Initialize() override;

	// 返回按钮点击事件
	UFUNCTION()
		void BackBtnClickedEvent();
	// 注册按钮点击事件
	UFUNCTION()
		void RegisterBtnClickedEvent();
	// 账号注册方法
	void RegisterFromServer(FString& UserName, FString& Password);
	// 请求响应方法
	void RequestComplate(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
	
};
