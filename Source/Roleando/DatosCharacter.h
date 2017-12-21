#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "DatosCharacter.generated.h"

USTRUCT(BlueprintType)
struct FDatosCharacter : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "CharacterInfo")  
	FString Character_Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "CharacterInfo")  
	FString Class_ID;
};
