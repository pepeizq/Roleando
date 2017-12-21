
#pragma once

#include "CoreMinimal.h"
#include "ICombateAccion.h"
#include "IDecisionHacedor.h"
#include "JuegoCharacter.h"
#include "Roleando.h" 
#include "TestDecisionHacedor.h"

enum class CombateFase : uint8 
{ 
	CPHASE_Decision, 
	CPHASE_Action, 
	CPHASE_Victory, 
	CPHASE_GameOver, 
};

class ROLEANDO_API CombateEngine
{

	bool esperandoPersonaje;

public:  
	
	TArray<UJuegoCharacter*> todosParty;  
	
	TArray<UJuegoCharacter*> playerParty;  
	
	TArray<UJuegoCharacter*> enemyParty;
		 
	CombateFase fase;

	CombateEngine(TArray<UJuegoCharacter*> playerParty, TArray<UJuegoCharacter*> enemyParty);  
	
	~CombateEngine();

	bool Tick(float DeltaSeconds);

protected:  
	
	UJuegoCharacter* currentTickTarget;  
	
	int tickTargetIndex;

	void EstablecerFase(CombateFase phase); 
	
	void CambiarPersonaje();

};
