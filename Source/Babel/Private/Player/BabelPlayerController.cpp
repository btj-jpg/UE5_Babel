// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BabelPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

ABabelPlayerController::ABabelPlayerController()
{
	bReplicates = true;
}

void ABabelPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(PlayerContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(PlayerContext, 0);
	}
}

void ABabelPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(PlayerAction, ETriggerEvent::Triggered, this, &ABabelPlayerController::PlayerMove);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABabelPlayerController::PlayerLook);
	}
}

/* バインド用基本行動 start */

void ABabelPlayerController::PlayerMove(const FInputActionValue& Value)
{
	const FVector2d MovementVector = Value.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, MovementVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABabelPlayerController::PlayerLook(const FInputActionValue& Value)
{
	const FVector2D lookAxisVector = Value.Get<FVector2d>();
	
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerPitchInput(lookAxisVector.Y);
		ControlledPawn->AddControllerYawInput(lookAxisVector.X);
	}
}
