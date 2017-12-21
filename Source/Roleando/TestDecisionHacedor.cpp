
#include "TestDecisionHacedor.h"

#include "Roleando.h"
#include "TestCombateAccion.h"

void TestDecisionHacedor::EmpezarDecision(UJuegoCharacter* character)
{
	UJuegoCharacter* target = character->SeleccionarObjetivo();
	character->combateAccion = new TestCombateAccion(target);
}

bool TestDecisionHacedor::HacerDecision(float DeltaSeconds) 
{ 
	return true; 
}