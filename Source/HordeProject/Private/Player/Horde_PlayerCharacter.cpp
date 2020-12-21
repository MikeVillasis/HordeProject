// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Horde_PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AHorde_PlayerCharacter::AHorde_PlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	H_CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Character Camera Component"));
	H_CameraComponent->SetupAttachment(GetMesh());
	H_CameraComponent->bUsePawnControlRotation = true;

	UCharacterMovementComponent* ThisCharMovementComp = GetCharacterMovement();
	OriginalZVelocity = ThisCharMovementComp->JumpZVelocity;

	bIsJumping = false;


}

// Called when the game starts or when spawned
void AHorde_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHorde_PlayerCharacter::WalkForward(float InputValue)
{
	if (InputValue != 0)
	{
		AddMovementInput(GetActorForwardVector(), InputValue);
	}
}

void AHorde_PlayerCharacter::WalkSideways(float InputValue)
{
	if (InputValue != 0)
	{
		AddMovementInput(GetActorRightVector(), InputValue);
	}
}

void AHorde_PlayerCharacter::SimpleJump()
{
	if (bIsJumping == false)
	{
		UCharacterMovementComponent* ThisCharMovementComp = GetCharacterMovement();
		ThisCharMovementComp->JumpZVelocity = OriginalZVelocity * JumpForce;
		Super::Jump();
		bIsJumping = true;

	}
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
		// Camera Rotation based upon mouse axes
		PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
		PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

		// Character movement based upon input
		PlayerInputComponent->BindAxis("Forward", this, &AHorde_PlayerCharacter::WalkForward);
		PlayerInputComponent->BindAxis("Right", this, &AHorde_PlayerCharacter::WalkSideways);

		// Character Jumping

		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AHorde_PlayerCharacter::SimpleJump);

	}
}

