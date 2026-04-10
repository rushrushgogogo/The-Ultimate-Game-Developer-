#pragma once



UENUM(BlueprintType)
enum class ECharacterState : uint8 {
	ECS_IDLE UMETA(DisplayName = "IDLE"),
	ECS_EQUIP UMETA(DisplayName = "ECS_EQUIP")
};


UENUM(BlueprintType)
enum class EActionState : uint8 {
	EAS_IDLE UMETA(DisplayName = "IDLE"),
	EAS_ATTACK UMETA(DisplayName = "ATTACK"),
	EAS_HOLSTER UMETA(DisplayName = "HOLSTER"),
	EAS_DRAW	
};


UENUM(BlueprintType)
enum class EItemState : uint8 {
	EIS_IDLE UMETA(DisplayName = "IDLE"),
	EIS_EQUIP UMETA(DisplayName = "EQUIP")
};