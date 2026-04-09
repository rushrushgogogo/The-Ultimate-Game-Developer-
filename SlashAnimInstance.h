// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Slash/SlashCharacter.h"
#include "SlashAnimInstance.generated.h"

class UCharacterMovementComponent;


UCLASS()
class ANCIENTGAME_API USlashAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UPROPERTY(BlueprintReadOnly)
	ASlashCharacter* slashCharacter;
	UCharacterMovementComponent* slashMove;

	UPROPERTY(BlueprintReadOnly)
	float groudSpeed;

	UPROPERTY(BlueprintReadOnly)
	bool isFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Test | Test")
	ECharacterState characterState;
};
