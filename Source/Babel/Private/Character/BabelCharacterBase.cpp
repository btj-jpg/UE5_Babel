// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BabelCharacterBase.h"

// Sets default values
ABabelCharacterBase::ABabelCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABabelCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABabelCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABabelCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

