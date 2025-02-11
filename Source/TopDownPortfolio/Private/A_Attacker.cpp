#include "A_Attacker.h"
#include "A_Character_Base.h"

AA_Attacker::AA_Attacker() :
	AActor{}, m_pRoot{},m_arCollision{}, m_pOwner{}, m_bOnStart {}
{
	PrimaryActorTick.bCanEverTick = true;
	m_pRoot = CreateDefaultSubobject<USceneComponent>("Root");
	SetCanBeDamaged(false);
	SetRootComponent(m_pRoot);
}

void AA_Attacker::BeginPlay()
{
	AActor::BeginPlay();
	E_Init();
	if (GetParentActor())
	{
		SetInstigator(Cast<APawn>(GetParentActor()));
	}
	if (GetInstigator())
		m_pOwner = Cast< AA_Character_Base>(GetInstigator());
}

void AA_Attacker::E_Init()
{
	TArray<UPrimitiveComponent*> arComponent{};
	GetComponents < UPrimitiveComponent>(arComponent, true);
	m_arCollision.Reserve(arComponent.Num());
	for (UPrimitiveComponent* pCom : arComponent)
	{
		if (pCom->ComponentHasTag(E_GetCollisionTag()))
		{
			pCom->SetCollisionProfileName(E_GetCollisionProfile());
			pCom->OnComponentBeginOverlap.AddDynamic(this, &AA_Attacker::E_BeginOverlap);
			m_arCollision.Add(pCom);
		}
	}
	if (m_bOnStart)
	{
		E_On();
	}
}

void AA_Attacker::OnConstruction(const FTransform& Transform)
{
	AActor::OnConstruction(Transform);
}

void AA_Attacker::E_BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (E_CheckOverlap(OtherActor))
	{
		E_OverlapEvent(OtherActor);
	}
}

void AA_Attacker::E_SetAttackCollisionEnabled(ECollisionEnabled::Type eEnable)
{
	for (UPrimitiveComponent* pCom : m_arCollision)
	{
		pCom->SetCollisionEnabled(eEnable);
	}
}

void AA_Attacker::E_OnAttack()
{
	E_On();
}

void AA_Attacker::E_OffAttack()
{
	E_Off();
}

void AA_Attacker::E_OnOff(ECollisionEnabled::Type eEnable)
{
	E_SetAttackCollisionEnabled(eEnable);
}

