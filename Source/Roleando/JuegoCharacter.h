
#pragma once

#include "CombateEngine.h"
#include "CoreMinimal.h"
#include "DatosCharacter.h" 
#include "DatosCharacterClass.h"
#include "DatosEnemy.h"
#include "ICombateAccion.h"
#include "IDecisionHacedor.h"
#include "UObject/NoExportTypes.h"

#include "JuegoCharacter.generated.h"

UCLASS(BlueprintType)
class ROLEANDO_API UJuegoCharacter : public UObject
{
	GENERATED_BODY()

	//class CombateEngine;
	
public:  

	FDatosCharacterClass * ClassInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 MHP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 MMP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 MP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 ATK;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 DEF;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterInfo)  
	int32 LUCK;

	static UJuegoCharacter* CrearJuegoCharacter(FDatosCharacter* characterInfo, UObject* outer);

	static UJuegoCharacter* CrearJuegoCharacter(FDatosEnemy* enemyInfo, UObject* outer);

	void BeginDestroy() override;

	void EmpezarDecision();  
	
	bool HacerDecision(float DeltaSeconds);

	void EmpezarAccion();  
	
	bool HacerAccion(float DeltaSeconds);

	class CombateEngine* combateInstancia;

	class ICombateAccion* combateAccion;

	class IDecisionHacedor* decisionHacedor;

	bool isPlayer;

	class UJuegoCharacter* SeleccionarObjetivo();

protected:

	float testDelayTimer;
};
