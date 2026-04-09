// Fill out your copyright notice in the Description page of Project Settings.


#include "Slash/Item/Item_Sword.h"
#include "Slash/SlashCharacter.h"

void AItem_Sword::OnMySphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnMySphereOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

}
