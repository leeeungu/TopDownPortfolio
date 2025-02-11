#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "S_Buff.h"
#include "C_BuffMGR.generated.h"

class UO_Buff_Base;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWNPORTFOLIO_API UC_BuffMGR : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, Category = Data, meta = (AllowPrivateAccess = "true"))
	TArray< UO_Buff_Base*> m_arBuff;

public:	
	UC_BuffMGR();

protected:
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	void E_StartBuff(TSubclassOf< UO_Buff_Base> cBuff, FS_BuffData const& sData);
};
