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
	BlueprintCallable：Blueprintから呼び出せるようにする 
	Category：関数一覧のカテゴリ 
	          [|]で文字を区切るとカテゴリの階層を分けられる 
	          Categoriを設定しないと、Classカテゴリにクラス名が表示される
	*/
	UFUNCTION(BlueprintCallable, Category = "CPPBlueprintFunctionLibrary|Math|Calc")

	/*Pure化：実行ピンがないノードになる
	DisplayName(メタデータ指定子)：C++で宣言した関数名をBlueprintでは別名として表示できる
	Keywards(メタデータ指定子)：検索一覧の検索ワードを追加できる*/
	//UFUNCTION(BlueprintCallable, BlueprintPure, meta = (DisplayName = "Add", Keywards = "A+B"))

	//上の行にコメントを設定することで説明を変更できる
	//ノードにマウスオーバーするとTooltipにコメントに設定した文字列が表示される
	//設定しない場合は、メンバ関数名が表示される
	/* Tooltip descriotion */
	//UFUNCTION(BlueprintCallable,BlueprintPure)

	/*BlueprintNativeEvent：BlueprintとC++の両方でOverride出来るようにする*/
	//UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)

	/*BlueprintのみOverride出来るようにする*/
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEbent,BlueprintPure)
		static int Sum(const int A, const int B);
};
