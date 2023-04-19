// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPVariable.generated.h"

UCLASS()
class UEC_LECTURE_API ACPPVariable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPVariable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	// PrintString�֐���Duration�ɐݒ肷��ϐ�
	const float Duration = 10.0f;

	//PrintString�֐���TextColor�ɐݒ肷��ϐ�
	const FLinearColor TextColor = FLinearColor(0.0, 0.66, 1.0);

};
