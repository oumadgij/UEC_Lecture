// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPArrayManipulation.h"
#include "Kismet/KismetSystemLibrary.h"

// Called when the game starts or when spawned
void ACPPArrayManipulation::BeginPlay()
{
	Super::BeginPlay();

	/*******************************************************
	* �z����쐬����
	********************************************************/
	
	/*�z��̒�`*/
	TArray<FString> Fruits =
	{
		TEXT("Apple"),
		TEXT("Lemon"),
		TEXT("Banana")
	};

	/*Init�֐���,�����l�𐔎w��ŏ����l��ݒ�ł���*/
	TArray<FString> FruitsLocal;
	FruitsLocal.Init(TEXT("Apple"), 3);

	/*******************************************************
	* �z���Element��ǉ�����
	********************************************************/

	/*�z��ɒl��ǉ�����*/
	Fruits.Add(TEXT("Orange"));
	Fruits.Emplace(TEXT("Grape"));

	/*�d�����Ȃ��悤�ɔz��ɗv�f��ǉ�����*/
	Fruits.AddUnique(TEXT("Orange")); //�ǉ�
	Fruits.AddUnique(TEXT("Apple"));  //�d������̂Œǉ�����Ȃ�

	/*
	�E[Append]�͔z��̖����ɔz���ǉ��ł���
	�E[+=]���Z�q�ł�Append�Ɠ��l�ɔz���ǉ��ł���
	*/
	TArray<FString> Vegetables =
	{
		TEXT("Carrot"),
		TEXT("Tomato"),
		TEXT("Onion"),
	};
	//�z���ǉ�
	Fruits.Append(Vegetables);
	//�z���ǉ�
	Fruits += Vegetables;

	/*�w�肵��Index�ɗv�f��}������*/
	Fruits.Insert(TEXT("Orange"), 1);

	/*�w�肵�����ɂȂ�悤�ɔz���ǉ�����*/
	Fruits.SetNum(5);
	//���̔z�񐔂�菭�Ȃ��l���w�肵���ꍇ��
	//�w�肵���z�񐔂ɂȂ�悤�k�߂�
	Fruits.SetNum(2);

	/*******************************************************
	* �z���Element��z��̏����擾����
	********************************************************/

	/*[]���g���ėv�f���擾����*/
	FString Fruit = Fruits[1];

	/*�z��̃|�C���^���擾����*/
	FString* FruitPtr = Fruits.GetData();

	/*�z��̗v�f�����擾*/
	int32 Count = Fruits.Num();

	/*�v�f�̌^�̃T�C�Y���擾����*/
	uint32 ElementSize = Fruits.GetTypeSize();

	/*�z��̗v�f�̍Ō���擾����*/
	Fruits.Last();
	Fruits.Top();
	//Last��Index���w�肷��ƌ�납���Index�w��ɂȂ�
	Fruits.Last(0);

	/*******************************************************
	* forloop�̓z
	********************************************************/

	/*
	* �z��̐擪���珇�ԂɃ��[�J���ϐ��ɒl������
	* �z�񐔕�loop����
	*/
	for (FString Fruit : Fruits)
	{
		UKismetSystemLibrary::PrintString(this, Fruit, true, true, FColor::Cyan, 10.0f);
	}

	/*Index�̐��𑝂₵�Ȃ���Index�̗v�f���擾����loop����*/
	for (int32 Index = 0; Index < Fruits.Num(); Index++)
	{
		UKismetSystemLibrary::PrintString(this, Fruits[Index], true, true, FColor::Cyan, 10.0f);
	}

	/*******************************************************
	* �z���Element��ݒ肷��
	********************************************************/

	/*[]���g���ėv�f��ݒ肷��*/
	Fruits[0] = TEXT("Orange");

	/*******************************************************
	* �z���Element���폜����
	********************************************************/

	/*�z��̑S�Ă̗v�f����������*/
	Fruits.Empty();

	/*
	* �w�肵���l�ƈ�v����v�f���폜����
	* ��v����l����������ꍇ�͈�v�����l�̗v�f��S�č폜����
	*/
	Fruits.Remove(TEXT("Apple"));

	/*�擪�����ԋ߂��w�肵���l�ƈ�v����v�f���폜����*/
	Fruits.RemoveSingle(TEXT("Apple"));

	/*�w�肵��Index�̗v�f���폜����*/
	Fruits.RemoveAt(1);

	/*******************************************************
	* �z��𒲂ׂ�
	********************************************************/

	/*�w�肵��Index���L�����������𒲂ׂ�*/
	bool bValidM1 = Fruits.IsValidIndex(-1);
	bool bValid0 = Fruits.IsValidIndex(0);
	bool bValid5 = Fruits.IsValidIndex(5);

	// bValidM1 == false;
	// // bValid0  == true;
	// bValid5  == false;

	/*�w�肵���l���z��̗v�f�Ɋ܂܂�邩���ׂ�*/
	bool bApple = Fruits.Contains(TEXT("Apple"));
	bool bOrange = Fruits.Contains(TEXT("Orange"));

	// bApple  == true;
	// bOrange == false;

	/*����̏������܂܂�邩�𒲂ׂ�*/
	bool bLen6 = Fruits.ContainsByPredicate([](const FString& Str)
		{return Str.Len() == 6; });
	bool bLen7 = Fruits.ContainsByPredicate([](const FString& Str)
		{return Str.Len() == 7; });

	// bLen6 == true;
	// bLen7 == false;

	/*
	* Find�F�z��̐擪����w�肵���l�ƈ�v����Index���擾����
	* FindLast�F�z��̍Ō������w�肵���l�ƈ�v����Index���擾����
	* �l���������Ȃ���������[-1(INDEX_NONE)]��Ԃ�
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
	* �ŏ��Ɍ��o���ꂽ�v�f��Index��Ԃ��A������Ȃ�������
	* [-1(INDEX_NONE)]��Ԃ�
	*/
	int32 Index = Fruits.IndexOfByKey(TEXT("Apple"));

	// Index == 0

	/*
	* �w�肵�������ƈ�v�����l��Index��Ԃ�
	* ������Ȃ�������[-1(INDEX_NONE)]��Ԃ�
	*/
	int32 Index = Fruits.IndexOfByPredicate([](const FString& Str) {
		return Str.Contains(TEXT("Lemon"));});

	// Index == 1

	/*
	* �l�ƈ�v����Element�̃|�C���^��Ԃ�
	* ������Ȃ�������[nullptr]��Ԃ�
	*/
	FString* LemonPtr = Fruits.FindByKey(TEXT("Lemon")));
	FString* OrangePtr = Fruits.FindByKey(TEXT("Orange")));

	// LemonPtr  == &Fruits[1]
	// OrangePtr == nullptr

	/*
	* �w�肵�������ƈ�v�����l�̃|�C���^��Ԃ�
	* ������Ȃ�������unullptr�v��Ԃ�
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

	/*�����ɔz������ւ���*/
	SortArray.Sort();

	//�����ɏ]����Sort�����邱�Ƃ��ł���
	//�����������Ȃ�����Sort����
	SortArray.Sort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});

	/*�q�[�v�\�[�g�����s����*/
	//�����������Ȃ�����Sort����
	SortArray.HeapSort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});

	/*�X�e�C�u���\�[�g�����s����(���Ώ������ۏ؂����j*/
	// �����������Ȃ�����Sort����
	SortArray.StableSort([](const FString& A, const FString& B) {
		return A.Len() < B.Len();});
}