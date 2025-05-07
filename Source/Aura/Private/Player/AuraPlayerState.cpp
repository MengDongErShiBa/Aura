// Copyright Xile


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	// 敌人因为没有在服务器，直接在客户端初始化
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	// 开启网络复制
	AbilitySystemComponent->SetIsReplicated(true);
	// 玩家需要全部复制
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// 属性
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	// 设置网络复制频率
	SetNetUpdateFrequency(100.f);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
