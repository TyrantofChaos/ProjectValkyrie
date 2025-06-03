// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/StandardPlayerController.h"

void AStandardPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	this->SetInputMode(InputMode);
	
}
