// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VRCharacter.generated.h"

class UCameraComponent;
class USceneComponent;

UCLASS()
class SUPERLIMINALPSX_API AVRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVRCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
	UCameraComponent* activeCam = NULL;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Custom Box Trace function for Forced Perspective.	Determining Size of Object
	UFUNCTION(BlueprintCallable, Category = "Prop")
	void BoxTrace(USceneComponent* PickedObject, FVector StartBounds, float StartDistance, int StepSize, ETraceTypeQuery TraceChannel, TArray<AActor*> IgnoreActors, FVector& Location, float& Scale);


};
