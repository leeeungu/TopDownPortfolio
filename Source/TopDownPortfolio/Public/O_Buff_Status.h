#pragma once

#include "CoreMinimal.h"
#include "O_Buff_Base.h"
#include "O_Buff_Status.generated.h"

class AA_Character_Base;
enum class FE_StatusID : uint8;

UCLASS()
class TOPDOWNPORTFOLIO_API UO_Buff_Status : public UO_Buff_Base
{
	GENERATED_BODY()
private:
	AA_Character_Base* m_pOwner;
	FE_StatusID m_eStatuID;
	float m_fValuePerSecond;
public:
	UO_Buff_Status();

protected:
	virtual void E_SetBuffData(FS_BuffData const& sData) override;
	virtual void E_TimerFunction() override;
};
