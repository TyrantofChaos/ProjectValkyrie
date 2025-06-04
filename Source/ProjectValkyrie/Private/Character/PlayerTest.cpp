// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerTest.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../ProjectValkyrie.h"

APlayerTest::APlayerTest()
{
	// Set up spring arm for camera component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeLocation(FVector(0.f, 0.f, 60.f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 300.f;

	// Set Camera
	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = true;
	
}

void APlayerTest::BeginPlay()
{
	Super::BeginPlay();
	PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController)
	{
		// For Later Use
	}
	else
	{
		UE_LOG(PlayerLog, Error, TEXT("Need a player controller to create a widget"));
		this->Destroy();
	}
}

void APlayerTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APlayerTest::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Movement Controls
	PlayerInputComponent->BindAxis("TurnRight", this, &APlayerTest::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerTest::MoveForward);
	
}

void APlayerTest::MoveForward(float AxisValueY)
{
	if (AxisValueY != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), AxisValueY);
	}
}

void APlayerTest::MoveRight(float AxisValueX)
{
	if (AxisValueX != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), AxisValueX);
	}
}
