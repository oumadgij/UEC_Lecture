// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPVariable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetStringLibrary.h"

// Sets default values
ACPPVariable::ACPPVariable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPPVariable::BeginPlay()
{
	Super::BeginPlay();

	// �ϐ����쐬����
	FString Message = "C++ Hello World!";

	// Duration�ɕʂ̒l��ݒ肷��
	//Duration = 3.0f;

	// PrintString�m�[�h�Ɠ�������
	// UKismetSystemLibrary�N���X��PrintString�֐����Ăяo��
	//UKismetSystemLibrary::PrintString(this, Message, true, true, FColor::Cyan, Duration);

	//�ϐ��̌^��float����FString�ɕϊ�����
	//UKismetSystemLibrary::PrintString(
	//	this
	//	, UKismetStringLibrary::Conv_FloatToString(Duration) // Duration��float����FString�ɕϊ�����
	//	, true
	//	, true
	//	, FColor::Cyan
	//	, Duration);

	//Text�̃J���[���ɕϐ�TextColor��ݒ�                     // Text�̃J���[���ɕϐ�TextColor��ݒ�
	UKismetSystemLibrary::PrintString(this, Message, true, true, TextColor, Duration);
}

// Called every frame
void ACPPVariable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

