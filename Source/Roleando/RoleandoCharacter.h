
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RoleandoInterface.h"

#include "RoleandoCharacter.generated.h"

UCLASS()
class ROLEANDO_API ARoleandoCharacter : public ACharacter, public IRoleandoInterface
{
	GENERATED_BODY()

	ARoleandoCharacter(const class FObjectInitializer& ObjectInitializer);

public:
	
	virtual void MovimientoVertical(float Value);  
	
	virtual void MovimientoHorizontal(float Value);
	
};
