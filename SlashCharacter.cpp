#include "Slash/SlashCharacter.h"
#include "Slash/SlashAnimInstance.h"
#include "Slash/Item/Item.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GroomComponent.h"



ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	springarm = CreateDefaultSubobject<USpringArmComponent>(TEXT("name"));
	springarm->SetupAttachment(GetRootComponent());

	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("namename"));
	camera->SetupAttachment(springarm);

	hair = CreateDefaultSubobject<UGroomComponent>(TEXT("hair"));
	hair->SetupAttachment(GetMesh());
	hair->AttachmentName = FString("head");

	eyebrow = CreateDefaultSubobject<UGroomComponent>(TEXT("eyebrow"));
	eyebrow->SetupAttachment(GetMesh());
	eyebrow->AttachmentName = FString("head");

	GetCharacterMovement()->bOrientRotationToMovement = true;
}

// Called when the game starts or when spawned
void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASlashCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASlashCharacter::MoveYaw);
	PlayerInputComponent->BindAxis(FName("lookUp"), this, &ASlashCharacter::MovePitch);
	PlayerInputComponent->BindAction(FName("Jump"), IE_Pressed, this, &ASlashCharacter::Jump);
	PlayerInputComponent->BindAction(FName("F"), IE_Pressed, this, &ASlashCharacter::Equip);
}

void ASlashCharacter::MoveForward(float v)
{
	FVector dir = GetControlRotation().Vector();
	dir.Z = 0;
	dir.Normalize();
	AddMovementInput(dir, v);
}

void ASlashCharacter::MoveRight(float v)
{
	FVector dir = GetControlRotation().Vector();
	dir.Z = 0;
	dir.Normalize();

	dir = dir.RotateAngleAxis(90, FVector::UpVector);
	AddMovementInput(dir, v);
}

void ASlashCharacter::MoveYaw(float v)
{
	AddControllerYawInput(v);
}

void ASlashCharacter::MovePitch(float v)
{
	AddControllerPitchInput(v);
}

void ASlashCharacter::Jump()
{
}	

void ASlashCharacter::Equip()
{
	if (characterstate == ECharacterState::ECS_EQUIP) return;
	if (!overlappingItem or !overlappingItem->bSlashCharacterOverlapping) return;

	characterstate = ECharacterState::ECS_EQUIP;
	USlashAnimInstance* animInstance = Cast<USlashAnimInstance>(GetMesh()->GetAnimInstance());
	if (animInstance){
		animInstance->characterState = characterstate;
	}

	FAttachmentTransformRules rules(EAttachmentRule::SnapToTarget, false);
	overlappingItem->AttachToComponent(GetMesh(), rules, FName("hand_rSocket"));
}

