// Copyright Cristina Vasco 2018

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// Find the owner
	AActor *DoorOwner = GetOwner();
	
	// Print the rotation
	//FString DoorRotation = DoorOwner->GetActorRotation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("Rotation of Door Owner is %s")
	//	, *DoorRotation
	//);

	// Create a rotator
	FRotator NewRotation = FRotator(0.0f, 60.0f, 0.0f);

	// Set the door rotation
	DoorOwner->SetActorRotation(NewRotation);
	
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}
