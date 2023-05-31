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
	// �e�N���X�̃����o�֐�(public)
	void CallPublicFunc();

	// �e�N���X�̃f�[�^�����o(public)
	int VarPublicNum = 10;

protected:
	//�e�N���X�̃����o�֐�(protected)
	void CallProtectedFunc();

	//�e�N���X�̃f�[�^�����o(protected)
	int VarProtectedNum = 20;

private:
	//�e�N���X�̃����o�֐�(private)
	void CallPrivateFunc();

	//�e�N���X�̃f�[�^�����o(private)
	int VarPrivateNum = 30;
};
