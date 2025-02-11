#pragma once

#include "CoreMinimal.h"
#include "O_InputAction.h"
#include "O_InputAction_Skill.generated.h"

UCLASS()
class TOPDOWNPORTFOLIO_API UO_InputAction_Skill : public UO_InputAction
{
	GENERATED_BODY()
private:
public:
	UO_InputAction_Skill();

protected:
	virtual void E_Started(const FInputActionValue& fInputValue) override;
};
