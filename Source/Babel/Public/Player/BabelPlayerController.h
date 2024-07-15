// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BabelPlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class UInputAction;
/**
 * 
 */
UCLASS()
class BABEL_API ABabelPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	ABabelPlayerController();

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	// キーバインドマッピング系
	UPROPERTY(EditAnywhere, Category="Context")
	UInputMappingContext* PlayerContext;

	UPROPERTY(EditAnywhere, Category="Context")
	UInputAction* PlayerAction;

	UPROPERTY(EditAnywhere, Category="Context")
	UInputAction* LookAction;

	// 基本移動設定
	void PlayerMove(const FInputActionValue& Value);
	void PlayerLook(const FInputActionValue& Value);
	
};
