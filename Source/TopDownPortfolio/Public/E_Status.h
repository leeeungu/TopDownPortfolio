#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class FE_StatusID: uint8
{
	E_NONE UMETA(Hidden),
	E_HP,
	E_MP,
	E_DEFEND,
	E_ATTACK,
	E_EXP,
	E_MoveSpeed,
	//E_AttackSpeed,
	E_EnumMAX UMETA(Hidden),
};

UENUM(BlueprintType)
enum class FE_StatusType : uint8
{
	E_NONE UMETA(Hidden),
	E_Current,
	E_ValueMAX,
	E_EnumMAX UMETA(Hidden),
};

class TOPDOWNPORTFOLIO_API E_Status
{
private:
	float m_arType[(uint8)FE_StatusType::E_EnumMAX];
	FE_StatusID m_eID;
public:
	E_Status() = default;
	~E_Status() = default;

public:
	void E_SetID(FE_StatusID eType) { m_eID = eType; }
	float E_GetValue(FE_StatusType eType) { return m_arType[(uint8)eType]; }
	void E_SetValue(FE_StatusType eType, float fValue) { m_arType[(uint8)eType] = fValue; }
	void E_AddValue(FE_StatusType eType, float fValue) { m_arType[(uint8)eType] += fValue; }
};
