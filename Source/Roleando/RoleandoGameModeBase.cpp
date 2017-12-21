
#include "RoleandoGameModeBase.h"

#include "IJuegoInstancia.h"
#include "Kismet/GameplayStatics.h"
#include "RoleandoCharacter.h"
#include "RoleandoPlayerController.h"

ARoleandoGameModeBase::ARoleandoGameModeBase(const class FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	PlayerControllerClass = ARoleandoPlayerController::StaticClass();
	DefaultPawnClass = ARoleandoCharacter::StaticClass();
}

void ARoleandoGameModeBase::BeginPlay() 
{ 
	Cast<UIJuegoInstancia>(GetGameInstance())->Init(); 
}

void ARoleandoGameModeBase::Tick(float DeltaTime)
{
	if (this->actualCombateInstancia != nullptr)
	{
		bool combateTerminado = this->actualCombateInstancia->Tick(DeltaTime);

		if (combateTerminado)
		{
			if (this->actualCombateInstancia->fase == CombateFase::CPHASE_GameOver)
			{

			}
			else if (this->actualCombateInstancia->fase == CombateFase::CPHASE_Victory)
			{

			}

			UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(true);

			delete(this->actualCombateInstancia);
			this->actualCombateInstancia = nullptr;      
			this->enemyParty.Empty();

		}
	}
}

void ARoleandoGameModeBase::TestCombate()
{
	UDataTable* enemyTable = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), NULL, TEXT("DataTable'/Game/Tablas/Enemigos.Enemigos'")));

	if (enemyTable == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Enemies data table not found!"));    
		return;
	}

	FDatosEnemy* row = enemyTable->FindRow<FDatosEnemy>(TEXT("S1"), TEXT("LookupEnemyInfo"));

	if (row == NULL) 
	{ 
		UE_LOG(LogTemp, Error, TEXT("Enemy ID 'S1' not found!"));    
		return; 
	}

	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetActorTickEnabled(false);

	UJuegoCharacter* enemy = UJuegoCharacter::CrearJuegoCharacter(row, this);  
	this->enemyParty.Add(enemy);

	UIJuegoInstancia* juegoInstancia = Cast<UIJuegoInstancia>(GetGameInstance());

	this->actualCombateInstancia = new CombateEngine(juegoInstancia->PartyMembers, this->enemyParty);

	UE_LOG(LogTemp, Log, TEXT("Combat started"));

	/*this->CombateUIInstancia = CreateWidget<UCombateUIWidget>(GetGameInstance(), this->CombateUIClase); 
	this->CombateUIInstancia->AddToViewport();*/

	for (int i = 0; i < juegoInstancia->PartyMembers.Num(); i++)
	{
		//this->CombateUIInstancia->AñadirJugadorPanel(juegoInstancia->PartyMembers[i]);
	}

	for (int i = 0; i < this->enemyParty.Num(); i++)
	{
		//this->CombateUIInstancia->AñadirEnemigoPanel(this->enemyParty[i]);
	}

	/*this->CombateUIInstancia->RemoveFromViewport(); 
	this->CombateUIInstancia = nullptr;*/
}
 