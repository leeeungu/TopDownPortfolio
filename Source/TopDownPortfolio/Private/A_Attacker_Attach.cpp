#include "A_Attacker_Attach.h"
#include "A_Character_Base.h"
#include "C_AttackMGR.h"

AA_Attacker_Attach::AA_Attacker_Attach() :
	AA_Attacker{}, m_pAttackMGR{}
{
}

void AA_Attacker_Attach::BeginPlay()
{
	AA_Attacker::BeginPlay();
	if (m_pOwner)
		m_pAttackMGR = m_pOwner->E_GetAttackMGR();
}

bool AA_Attacker_Attach::E_CheckOverlap(AActor* pTarget)
{
	AA_Character_Base* pActor = Cast< AA_Character_Base>(pTarget);
	if (!pActor || pActor == m_pOwner)
		return false;
	return  m_pAttackMGR->E_IsAlreadyIn(pActor);
}

void AA_Attacker_Attach::E_OverlapEvent(AActor* pTarget)
{
	m_pAttackMGR->E_AddTarget(Cast< AA_Character_Base>(pTarget));
}

void AA_Attacker_Attach::E_On()
{
	E_SetAttackCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AA_Attacker_Attach::E_Off()
{
	E_SetAttackCollisionEnabled(ECollisionEnabled::NoCollision);
}
