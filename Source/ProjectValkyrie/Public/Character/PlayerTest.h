// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterTemp.h"
#include "PlayerTest.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTVALKYRIE_API APlayerTest : public ACharacterTemp
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	APlayerTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Variable) APlayerController* PlayerController;
	
private:
	void MoveForward(float AxisValueY);
	void MoveRight(float AxisValueX);

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly) class USpringArmComponent* SpringArm;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") class UCameraComponent* Camera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") float LookUpRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera") float TurnRate;
};
