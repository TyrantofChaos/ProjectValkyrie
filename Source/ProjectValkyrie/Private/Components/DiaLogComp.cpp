// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/DiaLogComp.h"
#include "LocTextHelper.h"
#include "NavigationSystemTypes.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Blueprint/UserWidget.h"
#include "Structs/DialogueStruct.h"
#include "VisualLogger/VisualLoggerTypes.h"
#include "Widgets/DialogueWidget.h"

// Sets default values for this component's properties
UDiaLogComp::UDiaLogComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDiaLogComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDiaLogComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDiaLogComp::Interact(AActor* InteractingActor)
{
	UE_LOG(DiaLog, Display, TEXT("Entering Interact Method"));
	// If Dialogue is done close widget
	if (EndDialogue)
	{
		if (ActiveDialogueWidget)
		{
			ActiveDialogueWidget->RemoveFromParent();
			ActiveDialogueWidget = nullptr;
		}
		EndDialogue = false;
		return;
	}

	// Get Data Table Row Node
	const FDialogueStruct* Row = nullptr;
	if (DataTable)
	{
		Row = DataTable->FindRow<FDialogueStruct>(RowName, TEXT("Dialogue Lookup"));
	}
	
	if (!Row)
	{
		
		UE_LOG(DiaLog, Warning, TEXT("Dialogue row '%s' not found in table '%s'."), *RowName.ToString(), *GetNameSafe(DataTable));
		return;
	}

	
	// Validate Widget
	if (!ActiveDialogueWidget && DialogueWidget)
	{
		UE_LOG(DiaLog, Warning, TEXT("Setting Active Dialogue Widget"));
		ActiveDialogueWidget = CreateWidget<UUserWidget>(GetWorld(), DialogueWidget);
		if (ActiveDialogueWidget) ActiveDialogueWidget->AddToViewport();			
	}

	// Now push the text to the widget (for both new and existing cases)
	if (ActiveDialogueWidget)
	{
		
		if (UDialogueWidget* DialogueUI = Cast<UDialogueWidget>(ActiveDialogueWidget))
		{
			UE_LOG(DiaLog, Display, TEXT("Checking Dialogue UI"));
			// Set Name for Text Box
			DialogueUI->SetSpeakerName(Name);
			UE_LOG(DiaLog, Display, TEXT("Name: %s"), *Name.ToString());
			// Set Dialogue to be displayed
			DialogueUI->SetDialogueText(Row->DialogueText);
			
		}
	}

	if (!Row->DialogueID.IsNone())
	{
		RowName = Row->DialogueID;
	}
	EndDialogue = Row->EndDialogue;

}

