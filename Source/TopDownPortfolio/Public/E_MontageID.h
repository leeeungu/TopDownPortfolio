#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"

class UAnimMontage;

UENUM(BlueprintType)
enum class FE_MontageID : uint8
{
	E_NONE UMETA(Hidden),
	E_01,
	E_02,
	E_03,
	E_04,
	E_EnumMAX  UMETA(Hidden),
};


class TOPDOWNPORTFOLIO_API E_MontageID
{
private:
	E_MontageID() = delete;
	~E_MontageID() = delete;
};
