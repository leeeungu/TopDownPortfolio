#pragma once

#include "CoreMinimal.h"

class UDataTable;
class UInputMappingContext;

class TOPDOWNPORTFOLIO_API D_DataTable
{
public:
	D_DataTable() = default;
	~D_DataTable() = default;

private:
	template<class T>
	T* E_Finder(const TCHAR* strFilePath);

	enum E_DefaultPath
	{
		E_Montage,
		E_Status,
		E_Skill,
		E_InputMapping
	};

	const TCHAR* E_GetDefault(E_DefaultPath eID)
	{
		const TCHAR* pResult{};
		switch (eID)
		{
		case E_DefaultPath::E_Montage:
			pResult = TEXT("/Game/02_Data/Montage/DT-MontageData-MM");
			// Script/Engine.DataTable'/Game/02_Data/Montage/DT-MontageData-MM.DT-MontageData-MM'
			break;
		case E_DefaultPath::E_Status:
			pResult = TEXT("/Game/02_Data/Status/DT-StatusData-MM");
			// Script / Engine.DataTable'/Game/02_Data/Status/DT-StatusData-MM.DT-StatusData-MM'
			break;
		case E_DefaultPath::E_InputMapping:
			pResult = TEXT("/Game/01_Blueprint/Input/IMC_Default");
			// Script/EnhancedInput.InputMappingContext'/Game/01_Blueprint/Input/IMC_Default.IMC_Default'
			break;
		case E_DefaultPath::E_Skill:
			pResult = TEXT("/Game/02_Data/Skill/DT-SkillData");
			// Script / Engine.DataTable'/Game/02_Data/Skill/DT-SkillData.DT-SkillData'
			break;
		default:
			break;
		}
		return pResult;
	}
public:
	UDataTable* E_Default_Montage();
	UDataTable* E_Default_Status();
	UDataTable* E_Default_Skiil();
	UInputMappingContext* E_Default_InputMapping();
};

template<class T>
inline T* D_DataTable::E_Finder(const TCHAR* strFilePath)
{
	T* pResult{};
	ConstructorHelpers::FObjectFinder<T> ObejctFind(strFilePath);
	if (ObejctFind.Succeeded())
		pResult = ObejctFind.Object;
	return pResult;
}