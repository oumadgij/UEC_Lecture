// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPStatic.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPStatic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Ã“Iƒƒ“ƒo•Ï”
	static int staticPoint;

	// ’Êí‚Ìƒƒ“ƒo•Ï”
	int normalPoint;
};
