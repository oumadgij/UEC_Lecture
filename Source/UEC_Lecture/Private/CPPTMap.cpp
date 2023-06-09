// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTMap.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPTMap::BeginPlay()
{
	Super::BeginPlay();

	//要素を追加
	FruitMap.Add(12, TEXT("Orange"));

	//要素を削除 削除したいKeyの値を入れる
	FruitMap.Remove(3);
	
	//TMapの中身を出力する
	for (TPair<int, FString>Elem : FruitMap)
	{
		UKismetSystemLibrary::PrintString(
			this
			, FString::Printf(TEXT("Key : %d Value : %s"), Elem.Key, *Elem.Value)
			, true
			, true
			, FColor::Cyan
			, 10.0f
		);
	}
}

