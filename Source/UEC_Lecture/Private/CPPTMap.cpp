// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPTMap.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPTMap::BeginPlay()
{
	Super::BeginPlay();

	//�v�f��ǉ�
	FruitMap.Add(12, TEXT("Orange"));

	//�v�f���폜 �폜������Key�̒l������
	FruitMap.Remove(3);
	
	//TMap�̒��g���o�͂���
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

