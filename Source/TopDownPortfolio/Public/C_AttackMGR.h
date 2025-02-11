#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <list>
#include "C_AttackMGR.generated.h"

class  AA_Attacker;
class AA_Character_Base;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWNPORTFOLIO_API UC_AttackMGR : public UActorComponent
{
	GENERATED_BODY()
protected:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FD_ChangeTarget, AA_Character_Base*, pOld, AA_Character_Base*, pNew);
	TArray<std::list< AA_Attacker*>> m_arAttacker;
	TSet< AA_Character_Base*> m_setTarget;
	AA_Character_Base* m_pOwner;

	AA_Character_Base* m_pTarget;
	float m_fMaxTime;
	float m_fTime;
public:
	UC_AttackMGR();

protected:
	virtual void BeginPlay() override;

	void E_CollisionEnable(std::list<AA_Attacker*>& arList, ECollisionEnabled::Type eType);

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction * ThisTickFunction) override;
	UPROPERTY(BlueprintCallable,BlueprintAssignable)
	FD_ChangeTarget OnTargetChange;
	bool E_AddTarget(AA_Character_Base* pTarget);
	void E_ResetTarget();
	void E_GetTargets(TArray<AA_Character_Base*>& arTargets);
	bool E_IsAlreadyIn(AA_Character_Base* pTarget);

	std::list< AA_Attacker*>* E_GetRegisterAttacker(uint8 nIndex);
	UFUNCTION(BlueprintCallable)
	void E_RegisterAttacker(uint8 nIndex, AActor* pAttacker);
	UFUNCTION(BlueprintCallable)
	void E_On(uint8 nIndex);
	UFUNCTION(BlueprintCallable)
	void E_Off(uint8 nIndex);
};
