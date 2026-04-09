#include "Slash/SlashAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Slash/SlashCharacter.h"

void USlashAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	slashCharacter = Cast<ASlashCharacter>(TryGetPawnOwner());
	if (!slashCharacter) return; 

	slashMove = slashCharacter->GetCharacterMovement();
}

void USlashAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!slashMove) return;
	groudSpeed = slashMove->Velocity.Size();
	isFalling = slashMove->IsFalling();
}

