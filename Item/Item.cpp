#include "Slash/Item/Item.h"
#include "Components/SphereComponent.h"
#include "Slash/SlashCharacter.h"


AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	sm = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM"));
	sm->SetupAttachment(GetRootComponent());

	sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	sphere->SetupAttachment(sm);
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	sphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnMySphereOverlap);
	sphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnMySphereEndOverlap);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnMySphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASlashCharacter* slashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (slashCharacter)
	{
		bSlashCharacterOverlapping = true;
		slashCharacter->SetOverlappingItem(this);
	}
}

void AItem::OnMySphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ASlashCharacter* slashCharacter = Cast<ASlashCharacter>(OtherActor);
	if (slashCharacter)
	{
		bSlashCharacterOverlapping = false;
		slashCharacter->SetOverlappingItem(nullptr);
	}
}

