// Fill out your copyright notice in the Description page of Project Settings.


#include "TakeRecorderController.h"

// Sets default values
ATakeRecorderController::ATakeRecorderController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATakeRecorderController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATakeRecorderController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

/**
* Reference Take Recorder panel then begin recording sequence
*/
void ATakeRecorderController::StartRecording() {
	UTakeRecorderPanel* panel = UTakeRecorderBlueprintLibrary::GetTakeRecorderPanel();
	if (panel != nullptr)
		panel->StartRecording();
}

/**
* Reference Take Recorder panel then stop recording sequence
*/
void ATakeRecorderController::StopRecording() {
	UTakeRecorderPanel* panel = UTakeRecorderBlueprintLibrary::GetTakeRecorderPanel();
	if (panel != nullptr)
		panel->StopRecording();
}

/**
* Reference Take Recorder panel then check if sequence is recording
* True if currently recording, false otherwise
*/
bool ATakeRecorderController::IsRecording() {
	return UTakeRecorderBlueprintLibrary::IsRecording();
}