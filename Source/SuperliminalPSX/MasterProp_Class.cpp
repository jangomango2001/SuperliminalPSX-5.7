// Fill out your copyright notice in the Description page of Project Settings.


#include "MasterProp_Class.h"
#include "IXRTrackingSystem.h"
#include "IHeadMountedDisplay.h"
#include "Engine/TextureRenderTarget2D.h"

// Sets default values
AMasterProp_Class::AMasterProp_Class()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMasterProp_Class::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMasterProp_Class::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMasterProp_Class::ResizeTextureTarget(UTextureRenderTarget2D *Texture, int32 Width, int32 Height)
{
    Texture->ResizeTarget(Width, Height);
}

void AMasterProp_Class::GetScreenSize(int& Width, int& Height)
{
    if (GEngine->XRSystem.IsValid())
    {
        IHeadMountedDisplay* HMD = GEngine->XRSystem->GetHMDDevice();
        if (HMD)
        {
            FIntPoint IdealRenderTargetSize;
            // This gets the resolution required to fill the HMD views
            IdealRenderTargetSize = HMD->GetIdealRenderTargetSize();

            Width = IdealRenderTargetSize.X;
            Height = IdealRenderTargetSize.Y;
            GEngine->AddOnScreenDebugMessage(0, 0.02, FColor::Yellow, FString::Printf(TEXT("%i = width / %i = height"), Width, Height));
        }
    }
    else {
        Width = 1920;
        Height = 1080;
    }
}

