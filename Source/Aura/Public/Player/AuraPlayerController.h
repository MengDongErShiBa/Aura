// Copyright Xile

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class IEnemyInterface;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();

	virtual void PlayerTick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	// 调用栈：
	// UWorld被创建,Tick过程中调用到GameMode的PostSeamlessTravel
	// PostSeamlessTravel:获取客户端中所有的PlayerController调用HandleSeamlessTravelPlayer
	// HandleSeamlessTravelPlayer：创建PlayerController，调用SetPlayer
	// SetPlayer:创建本地玩家，并调用InitInputSystem
	// InitInputSystem：创建PlayerInput，调用SetupInputComponent
	// SetupInputComponent:绑定各种输入事件
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> AuraContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

private:
	// 移动
	void Move(const FInputActionValue& InputActionValue);

	void CursorTrace();

	// 最后一个选中的敌人
	IEnemyInterface* LastActor;

	// 当前的敌人
	IEnemyInterface* ThisActor;
};
