// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/NPCTest.h"

ANPCTest::ANPCTest()
{
	DiaLogComp = CreateDefaultSubobject<UDiaLogComp>(TEXT("DialogueComponent"));
}

void ANPCTest::BeginPlay()
{
	Super::BeginPlay();
}

void ANPCTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
