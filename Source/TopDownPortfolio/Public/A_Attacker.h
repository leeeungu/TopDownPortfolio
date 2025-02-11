#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "A_Attacker.generated.h"

class AA_Character_Base;

UCLASS()
class TOPDOWNPORTFOLIO_API AA_Attacker : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* m_pRoot;
	TArray<UPrimitiveComponent*> m_arCollision; // save collision
	AA_Character_Base* m_pOwner;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool m_bOnStart;
public:	
	AA_Attacker();
	virtual void OnConstruction(const FTransform& Transform) override;
protected:
	virtual void BeginPlay() override;
	
protected:
	UFUNCTION()
	void E_BeginOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void E_SetAttackCollisionEnabled(ECollisionEnabled::Type eEnable);
	void E_Init();
	virtual bool E_CheckOverlap(AActor* pTarget) { return false; };
	virtual void E_OverlapEvent(AActor* pTarget) {};
	virtual void E_On() {};
	virtual void E_Off() {};
public:	
	UFUNCTION(BlueprintCallable)
	void E_OnAttack();
	UFUNCTION(BlueprintCallable)
	void E_OffAttack();

	UFUNCTION(BlueprintCallable)
	void E_OnOff(ECollisionEnabled::Type eEnable = ECollisionEnabled::QueryOnly);
	FName E_GetCollisionTag() { return "T_Attack"; }
	FName E_GetCollisionProfile() { return "P_Attack"; }
};
