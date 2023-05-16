// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(BluePrintType)

enum class ECPPCalcType : uint8   // <- :���� �Ō^���w��ł���
{
	Add       UMETA(DisplayName = "Addition"),
	Subtract  UMETA(DisplayName = "Suntraction"),
	Multiply  UMETA(DisplayName = "Multiplicattation"),
	Divide    UMETA(DisplayName = "Division"),
};