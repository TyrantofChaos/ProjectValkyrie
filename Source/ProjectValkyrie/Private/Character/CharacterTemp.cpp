// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterTemp.h"

// Sets default values
ACharacterTemp::ACharacterTemp()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->SetRelativeRotation(FRotator(0.f, -90.f, 0.f));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90.f));

	childActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("Child Actor"));
	//childActor->SetupAttachment(GetMesh(), TEXT("PlaceWeaponHere")); //use later after setting socket location and name
	
}

// Called when the game starts or when spawned
void ACharacterTemp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACharacterTemp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACharacterTemp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

