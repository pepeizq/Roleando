
#include "IJuegoInstancia.h"

void UIJuegoInstancia::Init()
{
	if (this->isInitialized)
	{
		return;
	}

	this->isInitialized = true;

	UDataTable* characters = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/Tablas/Personajes.Personajes'")));

	if (characters == NULL)
	{
		return;
	}

	FDatosCharacter* row = characters->FindRow<FDatosCharacter>(TEXT("S1"), TEXT("LookupCharacterClass"));

	if (row == NULL)
	{
		return;
	}

	this->PartyMembers.Add(UJuegoCharacter::CrearJuegoCharacter(row, this));
}


