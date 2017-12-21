
#pragma once

#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"

#include "RoleandoCameraComponent.generated.h"

UCLASS(meta = (BlueprintSpawnableComponent))
class ROLEANDO_API URoleandoCameraComponent : public UCameraComponent
{
	GENERATED_BODY()
	
public:  
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraProperties)  
	float CameraPitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraProperties)
	float CameraDistance;

	virtual void GetCameraView(float DeltaTime, FMinimalViewInfo& DesiredView) override;
};
