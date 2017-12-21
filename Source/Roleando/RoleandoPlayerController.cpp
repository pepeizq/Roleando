
#include "RoleandoPlayerController.h"

#include "GameFramework/Controller.h"
#include "RoleandoInterface.h"

void ARoleandoPlayerController::MovimientoVertical(float Value) 
{ 
	IRoleandoInterface* pawn = Cast<IRoleandoInterface>(GetPawn());
	
	if (pawn != NULL) 
	{ 
		pawn->MovimientoVertical(Value); 
	} 
}

void ARoleandoPlayerController::MovimientoHorizontal(float Value) 
{ 
	IRoleandoInterface* pawn = Cast<IRoleandoInterface>(GetPawn());
	
	if (pawn != NULL) 
	{ 
		pawn->MovimientoHorizontal(Value); 
	} 
}

void ARoleandoPlayerController::SetupInputComponent() 
{
	if (InputComponent == NULL) 
	{ 
		InputComponent = ConstructObject<UInputComponent>(UInputComponent::StaticClass(), this, TEXT("PC_InputComponent0"));    
		InputComponent->RegisterComponent(); 
	}

	InputComponent->BindAxis("MovimientoVertical", this, &ARoleandoPlayerController::MovimientoVertical);  
	InputComponent->BindAxis("MovimientoHorizontal", this, &ARoleandoPlayerController::MovimientoHorizontal);

	this->bShowMouseCursor = true;
}

