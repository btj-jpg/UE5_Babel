// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BabelPlayerCharacter.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ABabelPlayerCharacter::ABabelPlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Arm"));
	CameraComp->SetupAttachment(SpringArmComp);
}

void ABabelPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}