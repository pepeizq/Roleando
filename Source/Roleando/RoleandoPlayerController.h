
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "RoleandoPlayerController.generated.h"

UCLASS()
class ROLEANDO_API ARoleandoPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	void MovimientoVertical(float Value);  

	void MovimientoHorizontal(float Value);

	virtual void SetupInputComponent() override;
	
	
};
