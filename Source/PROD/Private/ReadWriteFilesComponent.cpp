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
	ParametersPath = FPaths::ProjectConfigDir();
	ParametersPath.Append(FileName);

	

	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	if (FileManager.FileExists(*ParametersPath))
	{
		if (FFileHelper::LoadFileToString(Parameters, *ParametersPath, FFileHelper::EHashOptions::None))
		{
			UE_LOG(LogTemp, Warning, TEXT("FileManipulation: Text From File: %s"), *Parameters);

			FString Split = ",";
			Parameters.Split( Split, &ParameterOne, &ParameterTwo, ESearchCase::Type::IgnoreCase);
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
