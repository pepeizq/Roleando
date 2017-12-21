
#include "JuegoCharacter.h"

#include "CombateEngine.h"

//UJuegoCharacter::UJuegoCharacter(const class FObjectInitializer& objectInitializer) : Super(objectInitializer) 
//{ 
//}

UJuegoCharacter* UJuegoCharacter::CrearJuegoCharacter(FDatosCharacter* characterInfo, UObject* outer)
{
	UJuegoCharacter* personaje = NewObject<UJuegoCharacter>(outer);

	UDataTable* characterClasses = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/Tablas/PersonajesClases.PersonajesClases'")));

	if (characterClasses != NULL)
	{
		personaje->CharacterName = characterInfo->Character_Name;

		FDatosCharacterClass* row = characterClasses->FindRow<FDatosCharacterClass>(*(characterInfo->Class_ID), TEXT("LookupCharacterClass"));
	
		personaje->ClassInfo = row;

		personaje->MHP = personaje->ClassInfo->StartMHP;    
		personaje->MMP = personaje->ClassInfo->StartMMP;    
		personaje->HP = personaje->MHP;    
		personaje->MP = personaje->MMP;

		personaje->ATK = personaje->ClassInfo->StartATK;    
		personaje->DEF = personaje->ClassInfo->StartDEF;    
		personaje->LUCK = personaje->ClassInfo->StartLuck;
	}

	personaje->isPlayer = true;

	return personaje;
}

UJuegoCharacter* UJuegoCharacter::CrearJuegoCharacter(FDatosEnemy* enemyInfo, UObject* outer)
{
	UJuegoCharacter* enemigo = NewObject<UJuegoCharacter>(outer);

	enemigo->CharacterName = enemyInfo->EnemyName; 
	enemigo->ClassInfo = nullptr;

	enemigo->MHP = enemyInfo->MHP;  
	enemigo->MMP = 0;  
	enemigo->HP = enemyInfo->MHP;  
	enemigo->MP = 0;

	enemigo->ATK = enemyInfo->ATK;  
	enemigo->DEF = enemyInfo->DEF;  
	enemigo->LUCK = enemyInfo->Luck;

	enemigo->isPlayer = false;

	return enemigo;
}

void UJuegoCharacter::BeginDestroy() 
{ 
	Super::BeginDestroy();
	delete(this->decisionHacedor);
}

void UJuegoCharacter::EmpezarDecision() 
{ 
	UE_LOG(LogTemp, Log, TEXT("Character %s making decision"), *this->CharacterName);
	//this->testDelayTimer = 1;
	//this->combateAccion = new TestCombateAccion();

	this->decisionHacedor = new TestDecisionHacedor();
	this->decisionHacedor->EmpezarDecision(this);	
}

bool UJuegoCharacter::HacerDecision(float DeltaSeconds) 
{ 
	//this->testDelayTimer -= DeltaSeconds;  
	//return this->testDelayTimer <= 0;

	//return true;

	this->decisionHacedor = new TestDecisionHacedor();
	return this->decisionHacedor->HacerDecision(DeltaSeconds);
}

void UJuegoCharacter::EmpezarAccion() 
{   
	UE_LOG(LogTemp, Log, TEXT("Character %s executing action"), *this->CharacterName);
	//this->testDelayTimer = 1; 
	this->combateAccion->EmpezarAccion(this);
}

bool UJuegoCharacter::HacerAccion(float DeltaSeconds) 
{ 
	//this->testDelayTimer -= DeltaSeconds;  
	//return this->testDelayTimer <= 0; 

	bool accionTerminada = this->combateAccion->HacerAccion(DeltaSeconds);  
	
	if (accionTerminada) 
	{ 
		delete(this->combateAccion);    
		return true; 
	}

	return false;
}

UJuegoCharacter* UJuegoCharacter::SeleccionarObjetivo()
{
	UJuegoCharacter* objetivo = nullptr;

	TArray<UJuegoCharacter*> listaObjetivos = this->combateInstancia->enemyParty;

	if (!this->isPlayer)
	{
		listaObjetivos = this->combateInstancia->playerParty;
	}

	for (int i = 0; i < listaObjetivos.Num(); i++) 
	{ 
		if (listaObjetivos[i]->HP > 0) 
		{ 
			objetivo = listaObjetivos[i];      
			break; 
		} 
	}

	if (objetivo->HP <= 0)
	{
		return nullptr;
	}

	return objetivo;
}