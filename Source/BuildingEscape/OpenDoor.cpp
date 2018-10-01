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

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	DoorOwner = GetOwner();
}

void UOpenDoor::OpenDoor()
{
	// Print the rotation
	//FString DoorRotation = DoorOwner->GetActorRotation().ToString();
	//UE_LOG(LogTemp, Warning, TEXT("Rotation of Door Owner is %s")
	//	, *DoorRotation
	//);

	FRotator OpenRotation = FRotator(0.0f, openAngle, 0.0f);
	DoorOwner->SetActorRotation(OpenRotation);
}


void UOpenDoor::CloseDoor()
{
	FRotator ClosedRotation = FRotator(0.0f, -90.0f, 0.0f);
	DoorOwner->SetActorRotation(ClosedRotation);
}

// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger Volume
	// If the ActorThatOpens is in the volume, open the door
	if (PressurePlate->IsOverlappingActor(ActorThatOpens)) {
		OpenDoor();
		overlapStart = GetWorld()->GetTimeSeconds();
	}
	
	// Check if it's time to close the door
	if (GetWorld()->TimeSince(overlapStart) > DoorCloseDelay)
	{
		CloseDoor();
	}
}

