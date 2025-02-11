#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "C_WidgetMGR.generated.h"

class APlayerController;
class UUserWidget;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWNPORTFOLIO_API UC_WidgetMGR : public UActorComponent
{
	GENERATED_BODY()
private:
	APlayerController* m_pController;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))

	TSubclassOf< UUserWidget> m_cMain;
	TSet< UUserWidget*> m_setWidget;
	UUserWidget* m_pMain;
public:	
	UC_WidgetMGR();

protected:
	virtual void BeginPlay() override;


	void E_Add(UUserWidget* pWidget);
	void E_Remove(UUserWidget* pWidget);

public:	

	UFUNCTION(BlueprintCallable)
	void E_AddWidget(UUserWidget* pWidget);
	UFUNCTION(BlueprintCallable)
	void E_RemoveWidget(UUserWidget* pWidget);

		
};
