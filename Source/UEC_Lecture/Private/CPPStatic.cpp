// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStatic.h"

// Static変数を初期化する
int ACPPStatic::staticPoint = 400;

void ACPPStatic::SetPoint(int myPoint)
{
	staticPoint = myPoint;
}