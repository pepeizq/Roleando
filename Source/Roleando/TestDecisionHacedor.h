
#pragma once

#include "IDecisionHacedor.h"

class ROLEANDO_API TestDecisionHacedor : public IDecisionHacedor
{

public:
	
	virtual void EmpezarDecision(UJuegoCharacter* character) override;  
	
	virtual bool HacerDecision(float DeltaSeconds) override;
};
