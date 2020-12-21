// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Horde_PlayerCharacter.generated.h"

class UCameraComponent;
UCLASS()
class HORDEPROJECT_API AHorde_PlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHorde_PlayerCharacter();

	//Default Player Camera Setup
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Camera")
		UCameraComponent* H_CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*=== CHARACTER MOVEMENT BEGINS ===*/
	void WalkForward(float InputValue);
	void WalkSideways(float InputValue);

	//Character Jump Settings
	void SimpleJump();
	float OriginalZVelocity;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement")
		float JumpForce;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*=== CHARACTER MOVEMENT ENDS ===*/
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	/* == Validations to be moved to a SM later == */
	bool bIsJumping;
	

};
