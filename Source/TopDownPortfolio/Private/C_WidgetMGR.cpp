#include "C_WidgetMGR.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"


UC_WidgetMGR::UC_WidgetMGR() :
	UActorComponent{}, m_pController{}, m_cMain{}, m_setWidget{}, m_pMain{}
{
	PrimaryComponentTick.bCanEverTick = false;
	m_setWidget.Reserve(20);

	ConstructorHelpers::FClassFinder<UUserWidget> ObejctFind(TEXT("/Game/01_Blueprint/Widget/W-Main"));
	// /Script/UMGEditor.WidgetBlueprint'/Game/01_Blueprint/Widget/W-Main.W-Main'

	if (ObejctFind.Succeeded())
		m_cMain = ObejctFind.Class;
}


void UC_WidgetMGR::BeginPlay()
{
	UActorComponent::BeginPlay();
	m_pController = Cast<APlayerController>(GetOwner());
	if (!m_pController || !m_cMain)
	{
		DestroyComponent();
		return;
	}
	if (m_cMain)
	{
		m_pMain = CreateWidget(m_pController, m_cMain);
		m_pMain->AddToViewport();
		//m_pMain->Slot->
		//UPanelWidget
		//m_pMain->GetRootWidget
	}
}

void UC_WidgetMGR::E_Add(UUserWidget* pWidget)
{
	if (!m_pMain)
		return;

}

void UC_WidgetMGR::E_Remove(UUserWidget* pWidget)
{
}

void UC_WidgetMGR::E_AddWidget(UUserWidget* pWidget)
{
	m_setWidget.Add(pWidget);
}

void UC_WidgetMGR::E_RemoveWidget(UUserWidget* pWidget)
{
	m_setWidget.Remove(pWidget);
}