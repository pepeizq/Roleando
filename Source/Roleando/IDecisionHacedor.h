
#pragma once

#include "JuegoCharacter.h"

class JuegoCharacter;

class IDecisionHacedor
{

public:
	
	virtual void EmpezarDecision(UJuegoCharacter* character) = 0;

	virtual bool HacerDecision(float DeltaSeconds) = 0;

};
