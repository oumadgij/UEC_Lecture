// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPAccessParent.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPAccessParent : public AActor
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// 親クラスのメンバ関数(public)
	void CallPublicFunc();

	// 親クラスのデータメンバ(public)
	int VarPublicNum = 10;

protected:
	//親クラスのメンバ関数(protected)
	void CallProtectedFunc();

	//親クラスのデータメンバ(protected)
	int VarProtectedNum = 20;

private:
	//親クラスのメンバ関数(private)
	void CallPrivateFunc();

	//親クラスのデータメンバ(private)
	int VarPrivateNum = 30;
};
