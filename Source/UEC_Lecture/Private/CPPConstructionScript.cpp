// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPConstructionScript.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPConstructionScript::ACPPConstructionScript()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// SceneComponentを作成する
	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	// SceneComponentをRootComponentに設定する
	RootComponent = DefaultSceneRoot;

	// StaticMeshComponentを作成する
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	// StaticMeshをLaodしてStaticMeshComponentのStaticMeshに設定する
	UStaticMesh* Mesh = LoadObject<UStaticMesh>(NULL, TEXT("/Engine/BasicShapes/Cube"), NULL, LOAD_None, NULL);
	StaticMesh->SetStaticMesh(Mesh);
	// StaticMeshComponentをRootComponentにAttachする
	StaticMesh->SetupAttachment(RootComponent);

	// ArrowComponentを作成する
	Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	// ArrowComponentの位置を設定する
	Arrow->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));
	// ArrowComponentをStaticMeshComponentにAttachする
	Arrow->SetupAttachment(StaticMesh);

	// PointLightComponentを作成する
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLightComponent"));
	// PointLightComponentの位置を設定する
	PointLight->SetRelativeLocation(FVector(130.0f, 0.0f, 0.0f));
	// PointLightComponentをStaticMeshComponentにAttachする
	PointLight->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void ACPPConstructionScript::BeginPlay()
{
	Super::BeginPlay();
	
	// 変数を作成する
	FString Message = "C++ Hello World!";

	// PrintStringノードと同じ処理
	// UKismetSystemLibraryクラスのPrintString関数を呼び出す
	UKismetSystemLibrary::PrintString(
		this, Message, true, true, TextColor, Duration);
}

void ACPPConstructionScript::OnConstruction(const FTransform& Transform)
{
	// PointLightの表示・非表示を設定
	PointLight->SetVisibility(bIsVisible);

	// PointLightの強さを設定
	PointLight->SetIntensity(Intensity);

	// PointLightのLightColorを設定
	PointLight->SetLightColor(LightColor);
}