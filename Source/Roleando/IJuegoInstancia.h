
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JuegoCharacter.h"

//#include "IJuegoInstancia.generated.h"

class UIJuegoInstancia : public UGameInstance
//UCLASS()
//class ROLEANDO_API UIJuegoInstancia : public UGameInstance
{
	//GENERATED_BODY()
	
	//UIJuegoInstancia(const class FObjectInitializer& ObjectInitializer);

public:  
	
	TArray<UJuegoCharacter*> PartyMembers;

	void Init();

protected:  
	
	bool isInitialized;

};
