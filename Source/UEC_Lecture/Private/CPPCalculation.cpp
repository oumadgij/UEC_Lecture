// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCalculation.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetMathLibrary.h"

// Called when the game starts or when spawned
void ACPPCalculation::BeginPlay()
{
	Super::BeginPlay();
	
	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	UKismetSystemLibrary::PrintString(
		this, Message, true, true, TextColor, Duration);

	// Add(�����Z)�̏���
	int32 ResultAdd = UKismetMathLibrary::Add_IntInt(CalcVarA, CalcVarB);
	// ��int32����FString�ɕϊ����Ă���
	FString StrResultAdd = UKismetStringLibrary::Conv_IntToString(ResultAdd);
	UKismetSystemLibrary::PrintString(
		this, StrResultAdd, true, true, FColor::Red, Duration);

	/* Add_IntInt��Conv_IntToString���g�p���Ȃ��v�Z�̎d�� */
	// Add(�����Z)
	/*int32 ResultAdd = CalcVarA + CalcVarB;
	FString StrResultAdd = FString::Printf(TEXT(% d), ResultAdd);
	UKismetSystemLibrary::PrintString(
		this, StrResultAdd, true, true, FColor::Red, Duration);*/
}