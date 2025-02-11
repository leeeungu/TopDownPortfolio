#include "O_InputAction_Skill.h"

UO_InputAction_Skill::UO_InputAction_Skill() :
	UO_InputAction{}
{
}

void UO_InputAction_Skill::E_Started(const FInputActionValue& fInputValue)
{
	AA_Character_Player* pPlayer = E_GetPlayerCharacter();
	if (!pPlayer)
		return;
	FE_SkillID eID = m_pController->E_GetSkillID(m_eID);
	pPlayer->E_Action(eID);
}

