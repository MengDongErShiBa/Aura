#pragma once
#include "AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

UCLASS()
class AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
public:
	AAuraCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
