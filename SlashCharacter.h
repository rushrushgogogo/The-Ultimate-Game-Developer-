#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UGroomComponent;
class AItem;

UENUM(BlueprintType)
enum class ECharacterState : uint8 {
	ECS_IDLE UMETA(DisplayName = "IDLE"),
	ECS_EQUIP UMETA(DisplayName = "ECS_EQUIP") // Enum Class State
};

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

	ECharacterState characterstate = ECharacterState::ECS_IDLE;

	UPROPERTY(VisibleAnywhere)
	AItem* overlappingItem = nullptr;

	void SetOverlappingItem(AItem* item) { overlappingItem = item; }

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
