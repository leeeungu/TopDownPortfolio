#include "D_DataTable.h"
#include "InputMappingContext.h"
#include "Engine/DataTable.h"

UDataTable* D_DataTable::E_Default_Montage()
{
	return E_Finder< UDataTable>(E_GetDefault(E_DefaultPath::E_Montage));
}

UDataTable* D_DataTable::E_Default_Status()
{
	return E_Finder< UDataTable>(E_GetDefault(E_DefaultPath::E_Status));
}

UDataTable* D_DataTable::E_Default_Skiil()
{
	return  E_Finder< UDataTable>(E_GetDefault(E_DefaultPath::E_Skill));;
}

UInputMappingContext* D_DataTable::E_Default_InputMapping()
{
	return E_Finder< UInputMappingContext>(E_GetDefault(E_InputMapping));
}
