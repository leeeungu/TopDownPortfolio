#include "A_PlayerController.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "E_Skill.h"

AA_PlayerController::AA_PlayerController() :
	APlayerController{}, m_pWidgetMGR{}, m_pInputActionMGR {}, m_pInterfaceMGR{}, FXCursor{}
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	m_pWidgetMGR = CreateDefaultSubobject<UC_WidgetMGR>("WidgetMGR");
	m_pInputActionMGR = CreateDefaultSubobject<UC_InputActionMGR>("InputActionMGR");
	m_pInterfaceMGR = CreateDefaultSubobject<UC_InterfaceMGR>("InterfaceMGR");
}

void AA_PlayerController::E_RegisterComponent(UActorComponent* pComponent)
{
	if (pComponent)
		pComponent->RegisterComponent();
}

void AA_PlayerController::E_SpawnEffect()
{
	FVector CachedDestination = E_GetInterfaceMGR()->E_GetLocation();
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
}

FE_SkillID AA_PlayerController::E_GetSkillID(FE_InputActionID eID)
{
	FE_SkillID eResult = FE_SkillID::E_NONE;
	switch (eID)
	{
	case FE_InputActionID::E_NONE:
		break;
	case FE_InputActionID::E_RMouseClick:
		break;
	case FE_InputActionID::E_LMouseClick:
		break;
	case FE_InputActionID::E_Q:
		eResult = FE_SkillID::E_01;
		break;
	case FE_InputActionID::E_W:
		eResult = FE_SkillID::E_02;
		break;
	case FE_InputActionID::E_E:
		eResult = FE_SkillID::E_03;
		break;
	default:
		break;
	}
	return eResult;
}

void AA_PlayerController::SetupInputComponent()
{
	APlayerController::SetupInputComponent();
	if (m_pInputActionMGR)
		m_pInputActionMGR->E_Init();
}

void AA_PlayerController::OnConstruction(const FTransform& Transform)
{
	APlayerController::OnConstruction(Transform);
	E_RegisterComponent(m_pWidgetMGR);
	E_RegisterComponent(m_pInputActionMGR);
	E_RegisterComponent(m_pInterfaceMGR);
}


void AA_PlayerController::Tick(float DeltaSeconds)
{
	APlayerController::Tick(DeltaSeconds);
}

