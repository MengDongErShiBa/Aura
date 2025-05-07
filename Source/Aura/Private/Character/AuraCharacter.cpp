#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	// 使用移动朝向
	GetCharacterMovement()->bOrientRotationToMovement = true;
	// 旋转速率
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	// 指示角色是否应该被限制在一个平面上。设置为 true 时，角色的移动将被限制在一个特定的平面（通常是 XY 平面），这意味着角色不会在 Z 轴上移动。
	GetCharacterMovement()->bConstrainToPlane = true;
	// 指示角色在开始移动时是否应该立即“吸附”到平面上。如果设置为 true，角色在开始移动时会被强制调整到平面上，确保角色的 Z 位置与平面对齐。
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// 不适用Controller旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

	// 设置Character的ASC和AttributeSet
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();
}
