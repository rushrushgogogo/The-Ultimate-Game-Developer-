// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Slash/Item/Item.h"
#include "Item_Sword.generated.h"

/**
 * 
 */
UCLASS()
class ANCIENTGAME_API AItem_Sword : public AItem
{
	GENERATED_BODY()
	
public:

protected:
	virtual void OnMySphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, 
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
