// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();

	// 変数を作成する
	FString Message = "C++ Hello World!";

	// Durationに別の値を設定する
	//Duration = 3.0f;

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	//UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, Duration);

	//変数の型をfloatからFStringに変換する
	//UKismetSystemLibrary::PrintString(
	//	this
	//	, UKismetStringLibrary::Conv_FloatToString(Duration) // DurationをfloatからFStringに変換する
	//	, true
	//	, true
	//	, FColor::Cyan
	//	, Duration);

	//Textのカラー情報に変数TextColorを設定                     // Textのカラー情報に変数TextColorを設定
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}