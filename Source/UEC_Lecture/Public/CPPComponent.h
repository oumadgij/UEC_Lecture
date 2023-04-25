// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "CPPComponent.generated.h"  //<-‚±‚ê‚Íˆê”Ô‰º!!!

UCLASS()
class UEC_LECTURE_API ACPPComponent : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// PrintStringŠÖ”‚ÌDuration‚ÉÝ’è‚·‚é•Ï”
	const float Duration = 10.0f;

	// PrintStringŠÖ”‚ÌTextColor‚ÉÝ’è‚·‚é•Ï”
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

public:
	// Scene Component
	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultSceneRoot;

	// StaticMesh Component
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	// Arrow Component
	UPROPERTY(VisibleAnywhere)
	UArrowComponent* Arrow;

	// Sets default values for this actor's properties
	ACPPComponent();
};
