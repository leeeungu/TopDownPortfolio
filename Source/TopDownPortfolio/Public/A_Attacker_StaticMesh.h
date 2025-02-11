#pragma once

#include "CoreMinimal.h"
#include "A_Attacker_Attach.h"
#include "A_Attacker_StaticMesh.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;

UCLASS()
class TOPDOWNPORTFOLIO_API AA_Attacker_StaticMesh : public AA_Attacker_Attach
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Attacker, meta = (AllowPrivateAccess = "true"))

	UStaticMeshComponent* m_pMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Attacker, meta = (AllowPrivateAccess = "true"))

	UCapsuleComponent* m_pCollision;

public:
	AA_Attacker_StaticMesh();
	
};
