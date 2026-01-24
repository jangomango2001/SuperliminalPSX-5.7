// Fill out your copyright notice in the Description page of Project Settings.


#include "VRCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AVRCharacter::AVRCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVRCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVRCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AVRCharacter::BoxTrace(USceneComponent* PickedObject, FVector StartBounds, float StartDistance, int StepSize, ETraceTypeQuery TraceChannel, TArray<AActor*> IgnoreActors, FVector& Location, float& Scale)
{
	float CurrentDistance;
	FVector Newlocation;
	FVector CurrentBounds = StartBounds;
	FHitResult Hit;
	for (int i = 10; i <= 500; i++) {
		CurrentDistance = i * StepSize;
		CurrentBounds = StartBounds * ((CurrentDistance / StartDistance) / GetActorScale3D().X);
		Newlocation = (activeCam->GetComponentLocation()) + (activeCam->GetForwardVector() * CurrentDistance);
		if (UKismetSystemLibrary::BoxTraceSingle(GetWorld(), Newlocation, Newlocation, CurrentBounds * 1.025, PickedObject->GetComponentRotation(), TraceChannel, false, IgnoreActors, EDrawDebugTrace::None, Hit, true)) {
			Location = Newlocation;
			Scale = ((CurrentDistance / StartDistance) / GetActorScale3D().X);
			return;
		}
	}
	Location = Newlocation;
	Scale = ((CurrentDistance / StartDistance) / GetActorScale3D().X);
}
