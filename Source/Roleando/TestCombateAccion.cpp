
#include "TestCombateAccion.h"

#include "JuegoCharacter.h"
#include "Roleando.h"

TestCombateAccion::TestCombateAccion(UJuegoCharacter* target) 
{ 
	this->objetivo = target; 
}

void TestCombateAccion::EmpezarAccion(UJuegoCharacter* character)
{
	this->personaje = character;

	if (this->objetivo->HP <= 0) 
	{ 
		this->objetivo = this->personaje->SeleccionarObjetivo(); 
	}

	if (this->objetivo == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("%s attacks %s"), *character->CharacterName, *objetivo->CharacterName);

	objetivo->HP -= 10;

	this->delayTimer = 1.0f;
}

bool TestCombateAccion::HacerAccion(float DeltaSeconds)
{
	this->delayTimer -= DeltaSeconds;  
	return this->delayTimer <= 0.0f;
}
