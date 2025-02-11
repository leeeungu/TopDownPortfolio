#include "C_InterfaceMGR.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/KismetMathLibrary.h"

UC_InterfaceMGR::UC_InterfaceMGR() :
	UActorComponent{}, m_pPlayerController{}, pInterfaceFunc{}, m_sHit{}, m_bHitSuccessful{}
{
	PrimaryComponentTick.bCanEverTick = false;
	pInterfaceFunc[(uint8)FE_InterfaceType::E_Touch] = &UC_InterfaceMGR::E_Set_TouchLocation;
	pInterfaceFunc[(uint8)FE_InterfaceType::E_Cursor] = &UC_InterfaceMGR::E_Set_CursorLocation;
}

void UC_InterfaceMGR::BeginPlay()
{
	UActorComponent::BeginPlay();
	m_pPlayerController = Cast<APlayerController>(GetOwner());
	if (!m_pPlayerController)
		DestroyComponent();
}

bool UC_InterfaceMGR::E_Set_TouchLocation(FHitResult& sHit)
{
	return m_pPlayerController->GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, sHit);
}

bool UC_InterfaceMGR::E_Set_CursorLocation(FHitResult& sHit)
{
	return m_pPlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, sHit);
}

void UC_InterfaceMGR::E_SetLocation(FE_InterfaceType eType)
{
	m_bHitSuccessful = (this->*pInterfaceFunc[(uint8)eType])(m_sHit);
}

FVector UC_InterfaceMGR::E_GetLocation()
{
	FVector fResult{};
	if (m_bHitSuccessful)
		fResult = m_sHit.Location;
	return fResult;
}

AActor* UC_InterfaceMGR::E_GetActor()
{
	AActor* pResult{};
	if (m_bHitSuccessful)
		pResult = m_sHit.GetActor();
	return pResult;
}

double UC_InterfaceMGR::E_GetAimAngle()
{
	double fAngle{};
	FHitResult sHit;
	bool bResult = E_Set_CursorLocation(sHit);
	if (bResult && m_pPlayerController->AcknowledgedPawn)
	{
		APawn* pPawn = m_pPlayerController->AcknowledgedPawn;
		FVector fMouse = sHit.Location - pPawn->GetActorLocation();
		fMouse.Normalize();
		FVector fForward = pPawn->GetActorForwardVector();
		fForward.Normalize();
		fAngle = FVector::CrossProduct(fForward, fMouse).Z;
		fAngle = UKismetMathLibrary::DegAsin(fAngle);
	}
	return fAngle;
}


