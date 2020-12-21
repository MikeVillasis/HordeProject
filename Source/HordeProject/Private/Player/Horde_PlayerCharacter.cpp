// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Horde_PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
AHorde_PlayerCharacter::AHorde_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	H_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Character Camera Component"));
	H_CameraComponent->SetupAttachment(GetMesh());
	H_CameraComponent->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void AHorde_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHorde_PlayerCharacter::WalkForward(float InputValue)
{

}

void AHorde_PlayerCharacter::WalkSideways(float InputValue)
{

}

// Called every frame
void AHorde_PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHorde_PlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if (PlayerInputComponent != NULL)
	{
		PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
		PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);
	}
}

