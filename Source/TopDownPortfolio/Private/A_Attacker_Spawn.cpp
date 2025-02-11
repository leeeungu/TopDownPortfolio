#include "A_Attacker_Spawn.h"
#include "A_Character_Base.h"
#include "C_StatusMGR.h"
#include "Engine/DamageEvents.h"

AA_Attacker_Spawn::AA_Attacker_Spawn() :
	AA_Attacker{}, m_setTarget{}
{
	m_setTarget.Reserve(5);
}

bool AA_Attacker_Spawn::E_CheckOverlap(AActor* pTarget)
{
	AA_Character_Base* pActor = Cast< AA_Character_Base>(pTarget);
	if (!pActor && pTarget == GetInstigator())
		return false;
	bool bResult{};
	return  m_setTarget.Contains(pActor);
}

void AA_Attacker_Spawn::E_OverlapEvent(AActor* pTarget)
{
	m_setTarget.Add(Cast< AA_Character_Base>(pTarget));
}

void AA_Attacker_Spawn::E_On()
{
	E_SetAttackCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AA_Attacker_Spawn::E_Off()
{
	float fDamage = m_pOwner->E_GetStatusMGR()->E_GetStatus_Current(FE_StatusID::E_ATTACK);
	FDamageEvent fDamageEvent{};
	for (AA_Character_Base* pTarget : m_setTarget)
	{
		pTarget->TakeDamage(fDamage, fDamageEvent, m_pOwner->GetController(), m_pOwner);
	}
	m_setTarget.Reset();
	E_SetAttackCollisionEnabled(ECollisionEnabled::NoCollision);
}

