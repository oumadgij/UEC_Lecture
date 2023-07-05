// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UEC_LECTURE_API CPPUProperty
{
public:
	//Blueoprint�Ȃ��ŕҏW����ۂ̕\���E�ҏW�̏��
	/*                       �\��   |  �ҏW�\
	* EditAnywhere�@�@�@�@|   �Z    |   �Z    
	* EditDefaultsOnly    |   �Z    |   �Z    
	* EditInstanceOnly    |   �Z    |   �Z    
	* VisibleAnywhere     |   �Z    |   �~    
	* VisibleDefaultsOnly |   �Z    |   �~    
	* VisibleInstanceOnly |   �Z    |   �~    
	*/

	//Viewport�ɔz�u����Instance������ۂ̕\���E�ҏW�̏��
	/*                       �\��   |  �ҏW�\
	* EditAnywhere�@�@�@�@|   �Z    |   �Z
	* EditDefaultsOnly    |   �~    |   �~    
	* EditInstanceOnly    |   �Z    |   �Z
	* VisibleAnywhere     |   �Z    |   �~
	* VisibleDefaultsOnly |   �~    |   �~
	* VisibleInstanceOnly |   �Z    |   �~
	*/

	/*
	* Category�FDetail�p�l���̃v���p�e�B���O���[�v���ł���
	*           �ݒ肷�镶�����[|]�ŋ�؂邱�ƂŃJ�e�S�������K�w�����Ă܂Ƃ߂���
	*/


	UPROPERTY(EditAnywhere, Category = "Reference|Edit")
		float NumEditAnywhere;

	UPROPERTY(EditDefaultsOnly, Category = "Reference|Edit")
		float NumEditDefaultsOnly;

	UPROPERTY(EditInstanceOnly, Category = "Reference|Edit")
		float NumEditInstanceOnly;

	UPROPERTY(VisibleAnywhere, Category = "Reference|Visible")
		float NumVisibleAnywhere;

	UPROPERTY(VisibleDefaultsOnly, Category = "Reference|Visible")
		float NumVisibleDefaultsOnly;

	UPROPERTY(VisibleInstanceOnly, Category = "Reference|Visible")
		float NumVisibleInstanceOnly;

	/*EditCondition�F�����o�ϐ��̕ҏW��L���E�����̃`�F�b�N�{�b�N�X�ŕ\������*/
	//UPROPERTY(EditAnywhere, meta = (EditCondition = "bEditCondition"), Category = "Reference|Edit")

	/*[meta = (EditCondition = "!Boolean�̕ϐ���")]�̂悤��Boolean�ϐ��̑O��[!]�����邱�Ƃ�Boolean�ϐ��̒l�𔽓]�ł���*/
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bEditCondition"), Category = "Reference|Edit")
		float NumEditCondition;
	UPROPERTY()
		bool bEditCondition;

	/*AdvancedDisplay�F���ڍׂȐݒ�����邽�߂́A�J�e�S���Ƃ��ĕ\��*/
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Reference")
		float NumAdvancedDisplay;

	/*
	BlueprintReadOnly�EBlueprintReadWrite
	Get/Set�m�[�h��EventGraph�ɒǉ��ł���悤�ɂ���
	�ǂ��炩�P�����ݒ�ł��Ȃ�
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ReadWrite")
		float NumBlueprintReadOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReadWrite")
		float NumBlueprintReadWrite;
};
