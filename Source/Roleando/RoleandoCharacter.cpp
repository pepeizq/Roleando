
#include "RoleandoCharacter.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"

ARoleandoCharacter::ARoleandoCharacter(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;  	
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 0.0f, 540.0f);  
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

void ARoleandoCharacter::MovimientoVertical(float Value)
{
	if (Controller != NULL && Value != 0.0f)
	{
		const FVector movimientoDireccion = FVector(1, 0, 0);    
		AddMovementInput(movimientoDireccion, Value);
	}
}

void ARoleandoCharacter::MovimientoHorizontal(float Value)
{
	if (Controller != NULL && Value != 0.0f)
	{
		const FVector movimientoDireccion = FVector(0, 1, 0);
		AddMovementInput(movimientoDireccion, Value);
	}
}


