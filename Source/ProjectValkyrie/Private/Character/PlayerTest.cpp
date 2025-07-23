// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerTest.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "../ProjectValkyrie.h"
#include "Components/DiaLogComp.h"

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

	// Set Sphere Collider
	InteractSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractSphere"));
	InteractSphere->SetupAttachment(RootComponent);
	InteractSphere->InitSphereRadius(150.f);
	InteractSphere->SetHiddenInGame(false);
	InteractSphere->SetVisibility(true);

	// Set up Overlap Events
	InteractSphere->OnComponentBeginOverlap.AddDynamic(this, &APlayerTest::OnBeginOverlap);
	InteractSphere->OnComponentEndOverlap.AddDynamic(this, &APlayerTest::OnEndOverlap);
	
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

	// Camera Controls
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerTest::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerTest::AddControllerYawInput);

	// Start Interact Call
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &APlayerTest::PlayerInteract);
}

void APlayerTest::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || OtherActor == this) return;

	// See if this actor has DiaLog Component
	if (OtherActor->FindComponentByClass<UDiaLogComp>())
	{
		DialogueActor = OtherActor; // Store this actor for later interaction
		UE_LOG(PlayerLog, Display, TEXT("Player can interact with: %s"), *OtherActor->GetName());
	}
}

void APlayerTest::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (DialogueActor) DialogueActor = nullptr;
}

void APlayerTest::PlayerInteract()
{
	if (DialogueActor)
	{
		if (UDiaLogComp* DiaLogComp = DialogueActor->GetComponentByClass<UDiaLogComp>())
		{
			DiaLogComp->Interact(this);
			UE_LOG(PlayerLog, Display, TEXT("Interacted with: %s"), *DialogueActor->GetName());
		}
	}
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
