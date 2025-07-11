// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "DiaLogComp.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTVALKYRIE_API UDiaLogComp : public UActorComponent
{
	GENERATED_BODY()

// For Method Creation
public:	
	// Sets default values for this component's properties
	UDiaLogComp();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

// Used for variable creation
private:
	UPROPERTY(EditDefaultsOnly, Category = "DataTable") UDataTable* DataTable;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DataTable") FName RowName;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText Name;		
};
