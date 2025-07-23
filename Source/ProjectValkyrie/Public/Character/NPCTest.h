// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterTemp.h"
#include "../Components/DiaLogComp.h"
#include "NPCTest.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTVALKYRIE_API ANPCTest : public ACharacterTemp
{
	GENERATED_BODY()

public:
	ANPCTest();
protected:
	virtual void BeginPlay() override;
public:
	virtual void Tick(float DeltaTime) override;

// Properties
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components) UDiaLogComp* DiaLogComp;
protected:
private:

// Functions
public:
protected:
private:
};
