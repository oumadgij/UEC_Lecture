// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class UEC_LECTURE_API CPPUProperty
{
public:
	//Blueoprintないで編集する際の表示・編集の状態
	/*                       表示   |  編集可能
	* EditAnywhere　　　　|   〇    |   〇    
	* EditDefaultsOnly    |   〇    |   〇    
	* EditInstanceOnly    |   〇    |   〇    
	* VisibleAnywhere     |   〇    |   ×    
	* VisibleDefaultsOnly |   〇    |   ×    
	* VisibleInstanceOnly |   〇    |   ×    
	*/

	//Viewportに配置してInstance化する際の表示・編集の状態
	/*                       表示   |  編集可能
	* EditAnywhere　　　　|   〇    |   〇
	* EditDefaultsOnly    |   ×    |   ×    
	* EditInstanceOnly    |   〇    |   〇
	* VisibleAnywhere     |   〇    |   ×
	* VisibleDefaultsOnly |   ×    |   ×
	* VisibleInstanceOnly |   〇    |   ×
	*/

	/*
	* Category：Detailパネルのプロパティをグループ化できる
	*           設定する文字列を[|]で区切ることでカテゴリ内を階層化してまとめられる
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

	/*EditCondition：メンバ変数の編集を有効・無効のチェックボックスで表示する*/
	//UPROPERTY(EditAnywhere, meta = (EditCondition = "bEditCondition"), Category = "Reference|Edit")

	/*[meta = (EditCondition = "!Booleanの変数名")]のようにBoolean変数の前に[!]をつけることでBoolean変数の値を反転できる*/
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bEditCondition"), Category = "Reference|Edit")
		float NumEditCondition;
	UPROPERTY()
		bool bEditCondition;

	/*AdvancedDisplay：より詳細な設定をするための、カテゴリとして表示*/
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Reference")
		float NumAdvancedDisplay;

	/*
	BlueprintReadOnly・BlueprintReadWrite
	Get/SetノードをEventGraphに追加できるようにする
	どちらか１つしか設定できない
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ReadWrite")
		float NumBlueprintReadOnly;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ReadWrite")
		float NumBlueprintReadWrite;
};
