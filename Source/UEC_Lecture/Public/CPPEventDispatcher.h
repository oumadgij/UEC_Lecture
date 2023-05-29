// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPClacType.h"
#include "CPPEventDispatcher.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPEventDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	int32 Sum(int32 A, int32 B);

	// Action Mappings�ɐݒ肵��Action����������֐�
	void PressedActionPrintCalcResult();

	// Event Dispatcher[OnPrintHello]
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPrintHelloDelegate);

	UPROPERTY(BlueprintAssignable, Category = "CPP_BP")
	FPrintHelloDelegate OnPrintHello;

	ACPPEventDispatcher();

	// Custom Event[PrintHello]
	UFUNCTION()
	void PrintHello();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FString Message = "C++ Hello World!";

	// �v�Z���ʂ��o�͂���֐�
	void PrintCalcResult(const ECPPCalcType Type, const int32 A, const int32 B, const float PrintDuration);

	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	// PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FColor(255, 255, 255);

	// �v�Z�p�̕ϐ�
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// Flow Control�p�̕ϐ�
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

	// Input�ݒ�
	void SetupInput();

	// Input Event����������֐�
	void PressedH();

};