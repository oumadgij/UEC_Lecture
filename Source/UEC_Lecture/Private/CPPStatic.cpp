// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPStatic.h"

// Static�ϐ�������������
int ACPPStatic::staticPoint = 400;

void ACPPStatic::SetPoint(int myPoint)
{
	staticPoint = myPoint;
}