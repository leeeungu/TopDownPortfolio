#include "O_InputAction_Move.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
//#include "NiagaraSystem.h"
//#include "NiagaraFunctionLibrary.h"

UO_InputAction_Move::UO_InputAction_Move() :
	UO_InputAction{}, m_fShortPressThreshold{}, m_fFollowTime{}
{
	m_fShortPressThreshold = 0.3f;
	m_fFollowTime = 0.f;
}

void UO_InputAction_Move::E_Release()
{
	//FVector CachedDestination = m_pController->E_GetInterfaceMGR()->E_GetLocation();
	//UAIBlueprintHelperLibrary::SimpleMoveToLocation(m_pController, CachedDestination);
	m_pController->E_SpawnEffect();
	//UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
}

void UO_InputAction_Move::E_Triggered(const FInputActionValue& fInputValue)
{
//	m_fFollowTime += GetWorld()->GetDeltaSeconds();
	UC_InterfaceMGR* pMGR = m_pController->E_GetInterfaceMGR();
	pMGR->E_SetLocation(FE_InterfaceType::E_Cursor);
	APawn* ControlledPawn = Cast< APawn>(E_GetPlayerCharacter());
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (pMGR->E_GetLocation() - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void UO_InputAction_Move::E_Started(const FInputActionValue& fInputValue)
{
	//m_fFollowTime = 0.f;
	m_pController->StopMovement();
}

void UO_InputAction_Move::E_Canceled(const FInputActionValue& fInputValue)
{
	E_Release();
}

void UO_InputAction_Move::E_Completed(const FInputActionValue& fInputValue)
{
	
	E_Release();
}
