#pragma once

#include "CoreMinimal.h"
#include "A_Attacker.h"
#include "A_Attacker_Attach.generated.h"

class UC_AttackMGR;

UCLASS()
class TOPDOWNPORTFOLIO_API AA_Attacker_Attach : public AA_Attacker
{
	GENERATED_BODY()
protected:
	UC_AttackMGR* m_pAttackMGR;
public:
	AA_Attacker_Attach();

protected:
	virtual void BeginPlay() override;
	virtual bool E_CheckOverlap(AActor* pTarget) override;
	virtual void E_OverlapEvent(AActor* pTarget) override;
	virtual void E_On()  override;
	virtual void E_Off() override;
};
