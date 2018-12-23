// Fill out your copyright notice in the Description page of Project Settings.

#include "RegisterUserWidget.h"

// 初始化控件
bool URegisterUserWidget::Initialize()
{
	// 初始化控件须在UMG控件初始化之前，若控件未初始化则返回假
	if (!Super::Initialize())
	{
		return false;
	}

	// 初始化返回按钮
	BackBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Back")));
	// 初始化用户名输入框
	UserNameInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_User")));
	// 初始化密码输入框
	PasswordInput = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_Pwd")));
	// 初始化注册按钮
	RegisterBtn = Cast<UButton>(GetWidgetFromName(TEXT("Button_Register")));

	// 返回按钮点击事件
	BackBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::BackBtnClickedEvent);
	// 注册按钮点击事件
	RegisterBtn->OnClicked.AddDynamic(this, &URegisterUserWidget::RegisterBtnClickedEvent);

	return true;
}

// 返回按钮点击事件
void URegisterUserWidget::BackBtnClickedEvent()
{
}

// 注册按钮点击事件
void URegisterUserWidget::RegisterBtnClickedEvent()
{
	// 获取输入框文字
	FString UserName = UserNameInput->GetText().ToString();
	FString Password = PasswordInput->GetText().ToString();

	// 判断用户名密码是否合法
	if (UserName.Len() == 0 || Password.Len() == 0 )
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "UserName or password is none");
		return;
	}
	// 账号注册
	RegisterFromServer(UserName, Password);
}

// 账号注册方法
void URegisterUserWidget::RegisterFromServer(FString & UserName, FString & Password)
{
	// 定义 Json 字符串
	FString RegisterInfo;
	// 创建 Json 写入器
	TSharedRef<TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>> JsonWriter = TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>>::Create(&RegisterInfo);
	/* 开始写入*/
	JsonWriter->WriteObjectStart();

	JsonWriter->WriteValue(TEXT("user"), UserName);
	JsonWriter->WriteValue(TEXT("pwd"), Password);
	
	JsonWriter->WriteObjectEnd();
	JsonWriter->Close();
	/* 关闭写入*/
	//
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, RegisterInfo);

	// 创建 HTTP 请求
	TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
	// 设置请求方式
	HttpRequest->SetVerb(TEXT("POST"));
	// 设置请求头
	HttpRequest->SetHeader(TEXT("User-Agent"), "X-UnrealEngine-Agent");
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));
	// 设置 URL
	//HttpRequest->SetURL(TEXT("http://localhost/mywebpage.php"));
	HttpRequest->SetURL(TEXT("http://localhost:8001/gameSignUp/"));
	// 设置上传数据
	HttpRequest->SetContentAsString(RegisterInfo);
	// 设置请求成功后委托方法
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &URegisterUserWidget::RequestComplate);
	// 请求服务器
	HttpRequest->ProcessRequest();


}

// 请求响应方法
void URegisterUserWidget::RequestComplate(FHttpRequestPtr RequestPtr, FHttpResponsePtr ResponsePtr, bool bIsSuccess)
{
	if (!ResponsePtr.IsValid())
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "ResponsePtr is None");
	}
	// 判断响应状态是否正常
	else if (!EHttpResponseCodes::IsOk(ResponsePtr->GetResponseCode()))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "response is not ok");
		//return;
	}
	// 获取返回的值
	FString Data = ResponsePtr->GetContentAsString();
	// 创建一个 Json 对象
	TSharedPtr<FJsonObject> JsonObject;
	// 创建 Json 解析器
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Data);
	// Json 反序列化
	bool bIsParse = FJsonSerializer::Deserialize(JsonReader, JsonObject);
	// 判断是否解析成功
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
