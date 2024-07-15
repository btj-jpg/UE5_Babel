// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/BabelCharacterBase.h"
#include "BabelPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class BABEL_API ABabelPlayerCharacter : public ABabelCharacterBase
{
	GENERATED_BODY()

public:
	ABabelPlayerCharacter();
	virtual void Tick(float DeltaTime) override;
	
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess = "true"));
	class USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess = "true"));
	class UCameraComponent* CameraComp;
};
