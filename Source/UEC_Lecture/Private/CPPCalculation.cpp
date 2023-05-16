// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this, Message, true, true, TextColor, Duration);

	// Add(足し算)の処理
	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
	// ↓int32からFStringに変換している
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	UKismetSystemLibrary::PrintString(
		this, StrResultAdd, true, true, FColor::Red, Duration);

	/* Add_IntIntとConv_IntToStringを使用しない計算の仕方 */
	// Add(足し算)
	/*int32 ResultAdd = CalcVarA + CalcVarB;
	FString StrResultAdd = FString::Printf(TEXT(% d), ResultAdd);
	UKismetSystemLibrary::PrintString(
		this, StrResultAdd, true, true, FColor::Red, Duration);*/
}