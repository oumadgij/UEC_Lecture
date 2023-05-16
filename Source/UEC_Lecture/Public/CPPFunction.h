// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPClacType.h"
#include "CPPFunction.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPFunction : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// PrintStringŠÖ”‚ÌDuration‚Éİ’è‚·‚é•Ï”
	const float Duration = 10.0f;

	// PrintStringŠÖ”‚ÌTextColor‚Éİ’è‚·‚é•Ï”
	const FLinearColor TextColor = FColor(255, 255, 255);

	// ŒvZ—p‚Ì•Ï”
	int32 CalcVarA = 7;
	int32 CalcVarB = 3;

	// FlowControl—p‚Ì•Ï”
	bool IsPrintHello = false;
	ECPPCalcType CalcType = ECPPCalcType::Add;

public:
	int32 Sum(int32 A, int32 B);

};
