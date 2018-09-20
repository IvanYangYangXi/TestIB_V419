// Fill out your copyright notice in the Description page of Project Settings.

#include "StartGameMode.h"




void AStartGameMode::BeginPlay()
{
	// Êä³öÈÕÖ¾
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, TEXT("Hello,StartGameMode"));
}
