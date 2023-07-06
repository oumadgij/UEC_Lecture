// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPArrayManipulation.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPArrayManipulation::BeginPlay()
{
	Super::BeginPlay();

	/*******************************************************
	* 配列を作成する
	********************************************************/
	
	/*配列の定義*/
	TArray<FString> Fruits =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana")
	};

	/*Init関数で,同じ値を数指定で初期値を設定できる*/
	TArray<FString> FruitsLocal;
	FruitsLocal.Init(TEXT("Apple"), 3);

	/*******************************************************
	* 配列のElementを追加する
	********************************************************/

	/*配列に値を追加する*/
	Fruits.Add(TEXT("Orange"));
	Fruits.Emplace(TEXT("Grape"));

	/*重複しないように配列に要素を追加する*/
	Fruits.AddUnique(TEXT("Orange")); //追加
	Fruits.AddUnique(TEXT("Apple"));  //重複するので追加されない

	/*
	・[Append]は配列の末尾に配列を追加できる
	・[+=]演算子でもAppendと同様に配列を追加できる
	*/
	TArray<FString> Vegetables =
	{
		TEXT("Carrot"),
		TEXT("Tomato"),
		TEXT("Onion"),
	};
	//配列を追加
	Fruits.Append(Vegetables);
	//配列を追加
	Fruits += Vegetables;

	/*指定したIndexに要素を挿入する*/
	Fruits.Insert(TEXT("Orange"), 1);

	/*指定した数になるように配列を追加する*/
	Fruits.SetNum(5);
	//元の配列数より少ない値を指定した場合は
	//指定した配列数になるよう縮める
	Fruits.SetNum(2);

	/*******************************************************
	* 配列のElementや配列の情報を取得する
	********************************************************/

	/*[]を使って要素を取得する*/
	FString Fruit = Fruits[1];

	/*配列のポインタを取得する*/
	FString* FruitPtr = Fruits.GetData();

	/*配列の要素数を取得*/
	int32 Count = Fruits.Num();

	/*要素の型のサイズを取得する*/
	uint32 ElementSize = Fruits.GetTypeSize();

	/*配列の要素の最後を取得する*/
	Fruits.Last();
	Fruits.Top();
	//LastはIndexを指定すると後ろからのIndex指定になる
	Fruits.Last(0);

	/*******************************************************
	* forloopの奴
	********************************************************/

	/*
	* 配列の先頭から順番にローカル変数に値を入れて
	* 配列数分loopを回す
	*/
	for (FString Fruit : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit, true, true, FColor::Cyan, 10.0f);
	}

	/*Indexの数を増やしながらIndexの要素を取得してloopを回す*/
	for (int32 Index = 0; Index < Fruits.Num(); Index++)
	{
		UKismetSystemLibrary::PrintString(this, Fruits[Index], true, true, FColor::Cyan, 10.0f);
	}

	/*******************************************************
	* 配列のElementを設定する
	********************************************************/

	/*[]を使って要素を設定する*/
	Fruits[0] = TEXT("Orange");

	/*******************************************************
	* 配列のElementを削除する
	********************************************************/

	/*配列の全ての要素を消去する*/
	Fruits.Empty();

	/*
	* 指定した値と一致する要素を削除する
	* 一致する値が複数ある場合は一致した値の要素を全て削除する
	*/
	Fruits.Remove(TEXT("Apple"));

	/*先頭から一番近い指定した値と一致する要素を削除する*/
	Fruits.RemoveSingle(TEXT("Apple"));

	/*指定したIndexの要素を削除する*/
	Fruits.RemoveAt(1);

	/*******************************************************
	* 配列を調べる
	********************************************************/

	/*指定したIndexが有効か無効かを調べる*/
	bool bValidM1 = Fruits.IsValidIndex(-1);
	bool bValid0 = Fruits.IsValidIndex(0);
	bool bValid5 = Fruits.IsValidIndex(5);

	// bValidM1 == false;
	// // bValid0  == true;
	// bValid5  == false;

	/*指定した値が配列の要素に含まれるか調べる*/
	bool bApple = Fruits.Contains(TEXT("Apple"));
	bool bOrange = Fruits.Contains(TEXT("Orange"));

	// bApple  == true;
	// bOrange == false;

	/*特定の条件が含まれるかを調べる*/
	bool bLen6 = Fruits.ContainsByPredicate([](const FString& Str)
		{return Str.Len() == 6; });
	bool bLen7 = Fruits.ContainsByPredicate([](const FString& Str)
		{return Str.Len() == 7; });

	// bLen6 == true;
	// bLen7 == false;

	/*
	* Find：配列の先頭から指定した値と一致するIndexを取得する
	* FindLast：配列の最後尾から指定した値と一致するIndexを取得する
	* 値を見つけられなかった時は[-1(INDEX_NONE)]を返す
	*/
	int32 Index;
	Fruits.Find(TEXT("Apple"), Index);

	int32 IndexLast;
	Fruits.FindLast(TEXT("Apple"), IndexLast);

	int32 IndexNothing;
	Fruits.Find(TEXT("Orange"), IndexNothing);

	// Index        == 0
	// IndexLast    == 2
	// IndexNothing == -1

	/*
	* 最初に検出された要素のIndexを返し、見つからなかったら
	* [-1(INDEX_NONE)]を返す
	*/
	int32 Index = Fruits.IndexOfByKey(TEXT("Apple"));

	// Index == 0

	/*
	* 指定した条件と一致した値のIndexを返す
	* 見つからなかったら[-1(INDEX_NONE)]を返す
	*/
	int32 Index = Fruits.IndexOfByPredicate([](const FString& Str) {
		return Str.Contains(TEXT("Lemon"));});

	// Index == 1

	/*
	* 値と一致したElementのポインタを返す
	* 見つからなかったら[nullptr]を返す
	*/
	FString* LemonPtr = Fruits.FindByKey(TEXT("Lemon")));
	FString* OrangePtr = Fruits.FindByKey(TEXT("Orange")));

	// LemonPtr  == &Fruits[1]
	// OrangePtr == nullptr

	/*
	* 指定した条件と一致した値のポインタを返す
	* 見つからなかったら「nullptr」を返す
	*/
	FString* LemonPtr = Fruits.FindByPredicate([](const FString& Str) {
		return Str.Contains(TEXT("Lemon"));});
	FString* OrangePtr = Fruits.FindByPredicate([](const FString& Str) {
		return Str.Contains(TEXT("Orange"));});

	// LemonPtr  == &Fruits[1]
	// OrangePtr == nullptr

	/*******************************************************
	* Sort
	********************************************************/
	TArray<FString> SortArray = {
	TEXT("Apple"),
	TEXT("Lemon"),
	TEXT("Banana"),
	TEXT("Carrot"),
	TEXT("Tomato"),
	TEXT("Onion"),
	};

	/*昇順に配列を入れ替える*/
	SortArray.Sort();

	//条件に従ってSortさせることもできる
	//文字数が少ない順にSortする
	SortArray.Sort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});

	/*ヒープソートを実行する*/
	//文字数が少ない順にSortする
	SortArray.HeapSort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});

	/*ステイブルソートを実行する(相対順序が保証される）*/
	// 文字数が少ない順にSortする
	SortArray.StableSort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});
}