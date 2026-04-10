// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Slash/Misc.h"
#include "Item.generated.h"

class UStaticMeshComponent;
class USphereComponent;

UCLASS()
class ANCIENTGAME_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* sm;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* sphere;

	bool bSlashCharacterOverlapping = false;

	EItemState itemState = EItemState::EIS_IDLE;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnMySphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnMySphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:



};
