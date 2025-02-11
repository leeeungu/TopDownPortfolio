#include "C_BuffMGR.h"
#include "O_Buff_Base.h"

UC_BuffMGR::UC_BuffMGR() :
	UActorComponent{}
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UC_BuffMGR::BeginPlay()
{
	UActorComponent::BeginPlay();
}

void UC_BuffMGR::E_StartBuff(TSubclassOf<UO_Buff_Base> cBuff, FS_BuffData const& sData)
{
	UO_Buff_Base* pBuff = NewObject< UO_Buff_Base>(this, cBuff);
	if (pBuff)
	{
		m_arBuff.Add(pBuff);
		pBuff->E_SetBuffData(sData);
		pBuff->E_Register();
	}
}

