// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

/*
* Ensure to add the path to the Recorder plugin to project VC++ Directories -> Include Directories
* Path to be added: UE4 Installation Location -> Engine -> Plugins -> VirtualProduction -> Takes -> Source -> TakeRecorder -> Public
*/
#include "Recorder/TakeRecorderPanel.h"
#include "Recorder/TakeRecorderBlueprintLibrary.h"

#include "TakeRecorderController.generated.h"

UCLASS()
class MOTIONCAPTURE_API ATakeRecorderController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATakeRecorderController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Call to TakeRecorder panel to start recording sequence
	UFUNCTION(BlueprintCallable, Category = "Default")
		void StartRecording();

	// Call to TakeRecorder panel to stop recording sequence
	UFUNCTION(BlueprintCallable, Category = "Default")
		void StopRecording();

	// Returns true if sequence is currently recording, false otherwise
	UFUNCTION(BlueprintCallable, Category = "Default")
		bool IsRecording();
};
