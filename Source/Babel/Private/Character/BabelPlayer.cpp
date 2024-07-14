// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BabelPlayer.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ABabelPlayer::ABabelPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Arm"));
	CameraComp->SetupAttachment(SpringArmComp);
}

void ABabelPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
