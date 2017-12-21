
#pragma once

#include "ICombateAccion.h"

class TestCombateAccion : public ICombateAccion
{

protected:  
	
	float delayTimer;

	UJuegoCharacter* personaje;  
	
	UJuegoCharacter* objetivo;

public:

	virtual void EmpezarAccion(UJuegoCharacter* character) override;

	virtual bool HacerAccion(float DeltaSeconds) override;

	TestCombateAccion(UJuegoCharacter* objetivo);

};
