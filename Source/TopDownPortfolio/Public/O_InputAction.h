#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "A_PlayerController.h"
#include "A_Character_Player.h"
#include "EnhancedInputComponent.h"
#include "E_InputActionID.h"
#include "O_InputAction.generated.h"

class UInputAction;
class UEnhancedInputComponent;
struct FInputActionValue;
struct FEnhancedInputActionEventBinding;

enum class FE_InputTriggerEvent : uint8
{
	E_NONE UMETA(Hidden),
	E_Triggered,
	E_Started,
	E_Ongoing,
	E_Canceled,
	E_Completed,
	E_MAX UMETA(Hidden)
};

UCLASS()
class TOPDOWNPORTFOLIO_API UO_InputAction : public UObject
{
	GENERATED_BODY()
protected:
	UInputAction* m_pInputAction;
	AA_PlayerController* m_pController;
	FEnhancedInputActionEventBinding* m_arBinding[(uint8)FE_InputTriggerEvent::E_MAX];
	FE_InputActionID m_eID;
	bool m_bActive;
public:
	UO_InputAction();

	void E_Init(APlayerController* pController, UInputAction* pInputAction);
	void E_Delete();
private:
	void E_BindAction();
	void E_RemoveActionBinding();
	void E_RemoveActionBinding(UEnhancedInputComponent* pEnhancedInputComponent, FEnhancedInputActionEventBinding* pEventBinding);

protected:
	virtual void E_Init_After(APlayerController* pController, UInputAction* pInputAction);
	virtual void E_Triggered(const FInputActionValue& fInputValue);
	virtual void E_Started(const FInputActionValue& fInputValue);
	virtual void E_Ongoing(const FInputActionValue& fInputValue);
	virtual void E_Canceled(const FInputActionValue& fInputValue);
	virtual void E_Completed(const FInputActionValue& fInputValue);
	AA_PlayerController* E_GetPlayerController() { return m_pController; }
	AA_Character_Player* E_GetPlayerCharacter() { return Cast<AA_Character_Player>(m_pController->AcknowledgedPawn); }
public:
	void E_SetInputActionID(FE_InputActionID eID) { m_eID = eID; }
	bool E_GetActive();
	void E_SetActive(bool bValue);
};
