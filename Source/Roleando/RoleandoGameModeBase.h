
#pragma once

#include "CombateEngine.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "RoleandoGameModeBase.generated.h"

UCLASS()
class ROLEANDO_API ARoleandoGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	ARoleandoGameModeBase(const class FObjectInitializer& ObjectInitializer);
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

public:

	CombateEngine* actualCombateInstancia;

	TArray<UJuegoCharacter*> enemyParty;

	UFUNCTION(exec) 
	void TestCombate();

	//UPROPERTY() 
	//UCombateUIWidget* CombateUIInstancia;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI") 
	//TSubclassOf<class UCombateUIWidget> CombateUIClase;
};
