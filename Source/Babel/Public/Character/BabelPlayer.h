// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BabelCharacterBase.h"
#include "BabelPlayer.generated.h"

/**
 * 
 */
UCLASS()
class BABEL_API ABabelPlayer : public ABabelCharacterBase
{
	GENERATED_BODY()

public:
	ABabelPlayer();
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess = "true"));
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess = "true"));
	class UCameraComponent* CameraComp;
};
