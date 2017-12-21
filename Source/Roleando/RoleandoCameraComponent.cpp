
#include "RoleandoCameraComponent.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"

void URoleandoCameraComponent::GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView)
{
	UCameraComponent::GetCameraView(DeltaTime, DesiredView);

	DesiredView.Rotation = FRotator(CameraPitch, 0.0f, 0.0f);

	if (APawn* OwningPawn = Cast<APawn>(GetOwner())) 
	{ 
		FVector location = OwningPawn->GetActorLocation();    
		location -= DesiredView.Rotation.Vector() * CameraDistance;    
		DesiredView.Location = location; 
	}
}


