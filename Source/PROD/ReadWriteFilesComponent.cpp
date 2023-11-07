// Fill out your copyright notice in the Description page of Project Settings.


#include "ReadWriteFilesComponent.h"

// Sets default values for this component's properties
UReadWriteFilesComponent::UReadWriteFilesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UReadWriteFilesComponent::ReadFile(FString FileName)
{
	ParamPath = FPaths::ProjectConfigDir();
	ParamPath.Append(FileName);

	

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (FileManager.FileExists(*ParamPath))
	{
		if (FFileHelper::LoadFileToString(Parameters, *ParamPath, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *Parameters);
			Parameters.ParseIntoArrayLines(Lines);

			Lines[0].Split(TEXT(":"),&Text, &ParameterOne);
			Lines[1].Split(TEXT(":"),&Text, &ParameterTwo);
			
			UE_LOG(LogTemp, Warning, TEXT("Parameter One: %s"), *ParameterOne);
			UE_LOG(LogTemp, Warning, TEXT("Parameter two: %s"), *ParameterTwo);
			
		}

		else
      	{
         	UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Did not load text from file"));
			ParameterOne = "1";
			ParameterTwo = "1";
      	}

		
	}

	else
	{
		ParameterOne = "1";
		ParameterTwo = "1";
	}
}

void UReadWriteFilesComponent::WriteToFile(FString FileName, FString Event)
{
	LogPath = FPaths::ProjectConfigDir();
	LogPath.Append(FileName);

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (FileManager.FileExists(*LogPath))
	{
		FFileHelper::LoadFileToString(EventLog, *LogPath, FFileHelper::EHashOptions::None);
		EventLog.Append(LINE_TERMINATOR + FDateTime::Now().ToString() + ", " + Event);
		FFileHelper::SaveStringToFile(EventLog, *LogPath);
	}
	
}

// Called when the game starts
void UReadWriteFilesComponent::BeginPlay()
{
	Super::BeginPlay();
	// ...
	
}


// Called every frame
void UReadWriteFilesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}