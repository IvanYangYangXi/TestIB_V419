// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterUserWidget.h"

// ��ʼ���ؼ�
bool URegisterUserWidget::Initialize()
{
	// ��ʼ���ؼ�����UMG�ؼ���ʼ��֮ǰ�����ؼ�δ��ʼ���򷵻ؼ�
	if (!Super::Initialize())
	{
		return false;
	}

	// ��ʼ�����ذ�ť
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	// ��ʼ���û��������
	UserNameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_User")));
	// ��ʼ�����������
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Pwd")));
	// ��ʼ��ע�ᰴť
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));

	// ���ذ�ť����¼�
	BackBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::BackBtnClickedEvent);
	// ע�ᰴť����¼�
	RegisterBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::RegisterBtnClickedEvent);

	return true;
}

// ���ذ�ť����¼�
void URegisterUserWidget::BackBtnClickedEvent()
{
}

// ע�ᰴť����¼�
void URegisterUserWidget::RegisterBtnClickedEvent()
{
	// ��ȡ���������
	FString UserName = UserNameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();

	// �ж��û��������Ƿ�Ϸ�
	if (UserName.Len() == 0 || Password.Len() == 0 )
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "UserName or password is none");
		return;
	}
	// �˺�ע��
	RegisterFromServer(UserName, Password);
}

// �˺�ע�᷽��
void URegisterUserWidget::RegisterFromServer(FString & UserName, FString & Password)
{
	// ���� Json �ַ���
	FString RegisterInfo;
	// ���� Json д����
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	/* ��ʼд��*/
	JsonWriter->WriteObjectStart();

	JsonWriter->WriteValue(TEXT("user"), UserName);
	JsonWriter->WriteValue(TEXT("pwd"), Password);
	
	JsonWriter->WriteObjectEnd();
	JsonWriter->Close();
	/* �ر�д��*/
	//
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, RegisterInfo);

	// ���� HTTP ����
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	// ��������ʽ
	HttpRequest->SetVerb(TEXT("POST"));
	// ��������ͷ
	HttpRequest->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
	// ���� URL
	//HttpRequest->SetURL(TEXT("http://localhost/mywebpage.php"));
	HttpRequest->SetURL(TEXT("http://localhost:8001/gameSignUp/"));
	// �����ϴ�����
	HttpRequest->SetContentAsString(RegisterInfo);
	// ��������ɹ���ί�з���
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URegisterUserWidget::RequestComplate);
	// ���������
	HttpRequest->ProcessRequest();


}

// ������Ӧ����
void URegisterUserWidget::RequestComplate(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	if (!ResponsePtr.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "ResponsePtr is None");
	}
	// �ж���Ӧ״̬�Ƿ�����
	else if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "response is not ok");
		//return;
	}
	// ��ȡ���ص�ֵ
	FString Data = ResponsePtr->GetContentAsString();
	// ����һ�� Json ����
	TSharedPtr<FJsonObject> JsonObject;
	// ���� Json ������
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	// Json �����л�
	bool bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	// �ж��Ƿ�����ɹ�
	if (bIsParse)
	{
		FString Msg = JsonObject->GetStringField("msg");
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, Msg);
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "Can't Parse");
	}
}
