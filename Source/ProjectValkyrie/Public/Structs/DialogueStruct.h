#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DialogueStruct.generated.h"

USTRUCT(BlueprintType)
struct FDialogueStruct : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite) FText DialogueText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) FName DialogueID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) bool EndDialogue;
	
};