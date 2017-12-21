
#include "CombateEngine.h"

#include "JuegoCharacter.h"
#include "TestCombateAccion.h"
#include "TestDecisionHacedor.h"

CombateEngine::CombateEngine(TArray<UJuegoCharacter*> playerParty, TArray<UJuegoCharacter*> enemyParty)
{
	this->playerParty = playerParty;  
	this->enemyParty = enemyParty;

	for (int i = 0; i < playerParty.Num(); i++) 
	{ 
		this->todosParty.Add(playerParty[i]);
	}

	for (int i = 0; i < enemyParty.Num(); i++)
	{
		this->todosParty.Add(enemyParty[i]);
	}

	for (int i = 0; i < this->todosParty.Num(); i++) 
	{ 
		this->todosParty[i]->combateInstancia = this;
		//this->todosParty[i]->combateInstancia = nullptr;
	}

	this->tickTargetIndex = 0;  
	this->EstablecerFase(CombateFase::CPHASE_Decision);
}

CombateEngine::~CombateEngine()
{
	for (int i = 0; i < this->enemyParty.Num(); i++) 
	{ 
		this->enemyParty[i] = nullptr; 
	}

	for (int i = 0; i < this->todosParty.Num(); i++) 
	{ 
		this->todosParty[i]->combateInstancia = nullptr; 
	}
}

bool CombateEngine::Tick(float DeltaSeconds)
{
	switch (fase)
	{
		case CombateFase::CPHASE_Decision:
		{
			if (!this->esperandoPersonaje)
			{
				this->currentTickTarget->EmpezarDecision();
				this->esperandoPersonaje = true;
			}

			bool decisionHecha = this->currentTickTarget->HacerDecision(DeltaSeconds);

			if (decisionHecha)
			{
				CambiarPersonaje();

				if (this->tickTargetIndex == -1)
				{
					this->EstablecerFase(CombateFase::CPHASE_Action);
				}
			}
		}

		break;

		case CombateFase::CPHASE_Action:
		{
			if (!this->esperandoPersonaje)
			{
				this->currentTickTarget->EmpezarAccion();    
				this->esperandoPersonaje = true;
			}

			bool accionTerminada = this->currentTickTarget->HacerAccion(DeltaSeconds);

			if (accionTerminada)
			{
				CambiarPersonaje();

				if (this->tickTargetIndex == -1)
				{
					this->EstablecerFase(CombateFase::CPHASE_Decision);
				}
			}
		}
			
		break;

		case CombateFase::CPHASE_GameOver:    
		case CombateFase::CPHASE_Victory:

		return true;      
		break;
	}

	//----------------------------------------

	int deadCount = 0;  
	
	for (int i = 0; i < this->playerParty.Num(); i++) 
	{ 
		if (this->playerParty[i]->HP <= 0)
		{
			deadCount++;
		}
	}

	if (deadCount == this->playerParty.Num()) 
	{ 
		this->EstablecerFase(CombateFase::CPHASE_GameOver);
		return false; 
	}

	//----------------------------------------

	deadCount = 0;

	for (int i = 0; i < this->enemyParty.Num(); i++)
	{
		if (this->enemyParty[i]->HP <= 0)
		{
			deadCount++;
		}
	}

	if (deadCount == this->enemyParty.Num())
	{
		this->EstablecerFase(CombateFase::CPHASE_Victory);
		return false;
	}

	return false;
}

void CombateEngine::EstablecerFase(CombateFase phase)
{
	this->fase = phase;

	switch (phase)
	{
		case CombateFase::CPHASE_Action:
		case CombateFase::CPHASE_Decision:
			
			this->tickTargetIndex = 0;
			this->CambiarPersonaje();
			break;

		case CombateFase::CPHASE_Victory:

			break;

		case CombateFase::CPHASE_GameOver:

			break;
	}
}

void CombateEngine::CambiarPersonaje()
{
	this->esperandoPersonaje = false;

	for (int i = this->tickTargetIndex; i < this->todosParty.Num(); i++)
	{
		UJuegoCharacter* character = this->todosParty[i];

		if (character->HP > 0)
		{
			this->tickTargetIndex = i + 1;      
			this->currentTickTarget = character;      
			return;
		}
	}

	this->tickTargetIndex = -1;  
	this->currentTickTarget = nullptr;
}