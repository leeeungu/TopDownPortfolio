#include "O_Buff_Base.h"


UO_Buff_Base::UO_Buff_Base() : 
	UObject{}, m_sHandle{}, m_fInRate {}, m_fInFirstDelay{}, m_bLoop{}
{
	m_fInRate = 1.0f;
	m_fInFirstDelay = -1.0f;
	m_bLoop = false;
}

FTimerManager& UO_Buff_Base::E_GetTimer()
{
	return GetWorld()->GetTimerManager();
}

void UO_Buff_Base::E_Timer()
{
	E_TimerFunction();
	if (m_nCount > 0)
	{
		m_nCount -= 1;
	}
	if (m_nCount == 0)
	{
		E_UnRegister();
	}
}

void UO_Buff_Base::E_Register()
{
	E_GetTimer().SetTimer(m_sHandle, this, &UO_Buff_Base::E_Timer, m_fInRate, m_bLoop, m_fInFirstDelay);
}

void UO_Buff_Base::E_UnRegister()
{
	E_GetTimer().ClearTimer(m_sHandle);
	ConditionalBeginDestroy();
}
