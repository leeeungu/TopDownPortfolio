#include "C_AttackMGR.h"
#include "A_Attacker.h"
#include "A_Character_Base.h"

UC_AttackMGR::UC_AttackMGR() :
	UActorComponent{}, m_arAttacker{}, m_setTarget{}, m_pOwner{}, m_pTarget{}, m_fMaxTime{}, m_fTime {}, OnTargetChange{}
{
	PrimaryComponentTick.bCanEverTick = true;
	m_arAttacker.Init({}, 5);
	m_setTarget.Reserve(5);
	m_fMaxTime = 5.0f;
}

void UC_AttackMGR::BeginPlay()
{
	UActorComponent::BeginPlay();
	m_pOwner = Cast<AA_Character_Base>(GetOwner());
}

void UC_AttackMGR::E_CollisionEnable(std::list<AA_Attacker*>& arList, ECollisionEnabled::Type eType)
{
	for (AA_Attacker* pAttacker : arList)
	{
		pAttacker->E_OnOff(eType);
	}
}

void UC_AttackMGR::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UActorComponent::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (m_pTarget && m_fTime > 0)
	{
		m_fTime -= DeltaTime;
		if (m_fTime < 0)
		{
			if (OnTargetChange.IsBound())
				OnTargetChange.Broadcast(m_pTarget, nullptr);
		}
	}
}

bool UC_AttackMGR::E_AddTarget(AA_Character_Base* pTarget)
{
	bool bResult{};
	m_setTarget.Add(pTarget, &bResult);
	return bResult;
}

void UC_AttackMGR::E_ResetTarget()
{
	m_setTarget.Reset();
}

void UC_AttackMGR::E_GetTargets(TArray<AA_Character_Base*>& arTargets)
{
	arTargets = m_setTarget.Array();
}

bool UC_AttackMGR::E_IsAlreadyIn(AA_Character_Base* pTarget)
{
	return !m_setTarget.Contains(pTarget);
}

std::list<AA_Attacker*>* UC_AttackMGR::E_GetRegisterAttacker(uint8 nIndex)
{
	std::list<AA_Attacker*>* pResult{};
	if (m_arAttacker.IsValidIndex(nIndex))
		pResult = &m_arAttacker[nIndex];
	return pResult;
}

void UC_AttackMGR::E_RegisterAttacker(uint8 nIndex, AActor* pAttacker)
{
	if (!pAttacker)
		return;
	AA_Attacker* pAttack= Cast < AA_Attacker>(pAttacker);
	if (!m_arAttacker.IsValidIndex(nIndex) || !pAttack)
		return;
	m_arAttacker[nIndex].push_back(pAttack);
}

void UC_AttackMGR::E_On(uint8 nIndex)
{
	if (!m_arAttacker.IsValidIndex(nIndex))
		return;
	E_CollisionEnable(m_arAttacker[nIndex], ECollisionEnabled::QueryOnly);
}

void UC_AttackMGR::E_Off(uint8 nIndex)
{
	if (!m_arAttacker.IsValidIndex(nIndex))
		return;
	E_CollisionEnable(m_arAttacker[nIndex], ECollisionEnabled::NoCollision);
	for (AA_Character_Base* pTarget : m_setTarget)
	{
		m_pOwner->E_Attack(pTarget);
		if (!m_pTarget)
		{
			m_pTarget = pTarget;
			if (OnTargetChange.IsBound())
				OnTargetChange.Broadcast(nullptr, m_pTarget);

		}
		if (m_pTarget == pTarget)
		{
			m_fTime = m_fMaxTime;

		}
	}
	m_setTarget.Reset();
	//GetWorld()->GetTime
}

