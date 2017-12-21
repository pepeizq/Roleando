
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "DatosEnemy.generated.h"

USTRUCT(BlueprintType)
struct FDatosEnemy : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "EnemyInfo")    
	FString EnemyName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")    
	int32 MHP;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")    
	int32 ATK;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")    
	int32 DEF;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")
	int32 Luck;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "EnemyInfo")    
	TArray<FString> Abilities;
};

