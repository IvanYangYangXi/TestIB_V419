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
	// ���ذ�ť
	UPROPERTY()
		UButton* BackBtn;
	// �û��������
	UPROPERTY()
		UEditableTextBox* UserNameInput;
	// ���������
	UPROPERTY()
		UEditableTextBox* PasswordInput;
	// ע�ᰴť
	UPROPERTY()
		UButton* RegisterBtn;

public:
	// ��ʼ���ؼ�
	virtual bool Initialize() override;

	// ���ذ�ť����¼�
	UFUNCTION()
		void BackBtnClickedEvent();
	// ע�ᰴť����¼�
	UFUNCTION()
		void RegisterBtnClickedEvent();
	// �˺�ע�᷽��
	void RegisterFromServer(FString& UserName, FString& Password);
	// ������Ӧ����
	void RequestComplate(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess);
	
};
