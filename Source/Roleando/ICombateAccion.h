
#pragma once

#include "CoreMinimal.h"

class UJuegoCharacter;

class ROLEANDO_API ICombateAccion
{

public:
	
	virtual void EmpezarAccion(UJuegoCharacter* character) = 0;

	virtual bool HacerAccion(float DeltaSeconds) = 0;

};
