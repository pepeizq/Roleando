
#pragma once

#include "Object.h"
#include "UObject/Interface.h"

#include "RoleandoInterface.generated.h"

UINTERFACE()
class ROLEANDO_API URoleandoInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ROLEANDO_API IRoleandoInterface
{
	GENERATED_IINTERFACE_BODY()

	virtual void MovimientoVertical(float Valor);

	virtual void MovimientoHorizontal(float Valor);
};
