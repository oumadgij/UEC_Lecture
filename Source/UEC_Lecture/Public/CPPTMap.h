// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPTMap.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPTMap : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	//定義の仕方：TMap<(Keyの型), (Valueの型)> 変数名;
	TMap<int32, FString> FruitMap =
	{
		{3, TEXT("Apple")},
		{6, TEXT("Lemon")},
		{9, TEXT("Banana")},
	};
};
