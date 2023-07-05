// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPUFunction.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPUFunction : public AActor
{
	GENERATED_BODY()
public:	

	/*
	BlueprintCallable�FBlueprint����Ăяo����悤�ɂ��� 
	Category�F�֐��ꗗ�̃J�e�S�� 
	          [|]�ŕ�������؂�ƃJ�e�S���̊K�w�𕪂����� 
	          Categori��ݒ肵�Ȃ��ƁAClass�J�e�S���ɃN���X�����\�������
	*/
	UFUNCTION(BlueprintCallable, Category = "CPPBlueprintFunctionLibrary|Math|Calc")

	/*Pure���F���s�s�����Ȃ��m�[�h�ɂȂ�
	DisplayName(���^�f�[�^�w��q)�FC++�Ő錾�����֐�����Blueprint�ł͕ʖ��Ƃ��ĕ\���ł���
	Keywards(���^�f�[�^�w��q)�F�����ꗗ�̌������[�h��ǉ��ł���*/
	//UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Add", Keywards = "A+B"))

	//��̍s�ɃR�����g��ݒ肷�邱�ƂŐ�����ύX�ł���
	//�m�[�h�Ƀ}�E�X�I�[�o�[�����Tooltip�ɃR�����g�ɐݒ肵�������񂪕\�������
	//�ݒ肵�Ȃ��ꍇ�́A�����o�֐������\�������
	/* Tooltip descriotion */
	//UFUNCTION(BlueprintCallable,BlueprintPure)

	/*BlueprintNativeEvent�FBlueprint��C++�̗�����Override�o����悤�ɂ���*/
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)

	/*Blueprint�̂�Override�o����悤�ɂ���*/
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEbent,BlueprintPure)
		static int Sum(const int A, const int B);
};
