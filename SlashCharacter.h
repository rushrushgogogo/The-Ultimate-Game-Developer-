#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Slash/Misc.h"
#include "SlashCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UGroomComponent;
class AItem;
class UAnimMontage;


UCLASS()
class ANCIENTGAME_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;
	void MoveForward(float v);
	void MoveRight(float v);
	void MoveYaw(float v);
	void MovePitch(float v);
	void Jump();
	void Equip();
	void Attack();
	void PlayAttackMontage();
	UFUNCTION(BlueprintCallable)
	void AttackEnd();
	void EKey();
	void SetOverlappingItem(AItem* item) { overlappingItem = item; }
	UFUNCTION(BlueprintCallable)
	void HolsterEnd();
	UFUNCTION(BlueprintCallable)
	void DrawEnd();
	void SetActionState(EActionState newState);

	UPROPERTY(BlueprintReadWrite)
	ECharacterState characterstate = ECharacterState::ECS_IDLE;

	UPROPERTY(BlueprintReadWrite)
	EActionState actionstate = EActionState::EAS_IDLE;

	UPROPERTY(BlueprintReadWrite)
	AItem* overlappingItem = nullptr;


	UPROPERTY(BlueprintReadWrite)
	UStaticMeshComponent* sword = nullptr;

	// Montage
	UPROPERTY(EditDefaultsOnly, Category = Montage)
	UAnimMontage* attackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Montage)
	UAnimMontage* equipMontage;

protected:
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* springarm;

	
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* camera;

	UPROPERTY(VisibleAnywhere)
	UGroomComponent* hair;

	UPROPERTY(VisibleAnywhere)
	UGroomComponent* eyebrow;


};
