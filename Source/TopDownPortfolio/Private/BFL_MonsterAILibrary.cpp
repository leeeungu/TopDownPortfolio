#include "BFL_MonsterAILibrary.h"
#include "BehaviorTree/BTFunctionLibrary.h"

uint8 UBFL_MonsterAILibrary::E_GetBBEnum(UBTNode* NodeOwner, FName strKeyName)
{
	FBlackboardKeySelector sKey{};
	sKey.SelectedKeyName = strKeyName;
	return UBTFunctionLibrary::GetBlackboardValueAsEnum(NodeOwner, sKey);
}

void UBFL_MonsterAILibrary::E_SetBBEnum(UBTNode* NodeOwner, FName strKeyName, uint8 eEnum)
{
	FBlackboardKeySelector sKey{};
	sKey.SelectedKeyName = strKeyName;
	UBTFunctionLibrary::SetBlackboardValueAsEnum(NodeOwner, sKey, (uint8)eEnum);
}
