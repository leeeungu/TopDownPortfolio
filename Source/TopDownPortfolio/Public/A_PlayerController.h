#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_InputActionMGR.h"
#include "C_InterfaceMGR.h"
#include "C_WidgetMGR.h"
#include "A_PlayerController.generated.h"

class UNiagaraSystem;
enum class FE_SkillID :uint8;


UCLASS()
class TOPDOWNPORTFOLIO_API AA_PlayerController : public APlayerController
{
	GENERATED_BODY()
protected: 
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	UC_WidgetMGR* m_pWidgetMGR;
	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	UC_InputActionMGR* m_pInputActionMGR;

	UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
	UC_InterfaceMGR* m_pInterfaceMGR;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UNiagaraSystem* FXCursor;
public:
	AA_PlayerController();


protected:
	virtual void SetupInputComponent() override;
public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void OnConstruction(const FTransform& Transform) override;
protected:
	void E_RegisterComponent(UActorComponent* pComponent);
public:
	void E_SpawnEffect();
	FE_SkillID E_GetSkillID(FE_InputActionID eID);

	UFUNCTION(BlueprintPure)
	UC_InterfaceMGR* E_GetInterfaceMGR() { return m_pInterfaceMGR; }
	UFUNCTION(BlueprintPure)
	UC_InputActionMGR* E_GetInputActionMGR() { return m_pInputActionMGR; }
};
