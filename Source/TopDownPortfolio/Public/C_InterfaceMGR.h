#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_InterfaceMGR.generated.h"

class APlayerController;
struct FHitResult;

UENUM(BlueprintType)
enum class FE_InterfaceType : uint8
{
	E_NONE UMETA(Hidden),
	E_Cursor,
	E_Touch,
	E_MAX UMETA(Hidden)
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWNPORTFOLIO_API UC_InterfaceMGR : public UActorComponent
{
	GENERATED_BODY()
protected:
	APlayerController* m_pPlayerController;
	bool (UC_InterfaceMGR::*pInterfaceFunc[(uint8)FE_InterfaceType::E_MAX])(FHitResult& sHit);

	FHitResult m_sHit;
	bool m_bHitSuccessful;
public:	
	UC_InterfaceMGR();

protected:
	virtual void BeginPlay() override;
	bool E_Set_TouchLocation(FHitResult& sHit);
	bool E_Set_CursorLocation(FHitResult& sHit);

public:	
	void E_SetLocation(FE_InterfaceType eType);
	FVector E_GetLocation();
	AActor* E_GetActor();

	UFUNCTION(BlueprintCallable)
	double E_GetAimAngle();
};
