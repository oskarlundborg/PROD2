// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReadWriteFilesComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROD_API UReadWriteFilesComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UReadWriteFilesComponent();

	FString ParamPath;
	FString LogPath;
	FString Parameters;
	FString EventLog;

	UPROPERTY(BlueprintReadOnly)
	FString ParameterOne;
	UPROPERTY(BlueprintReadOnly)
	FString ParameterTwo;

	UFUNCTION(BlueprintCallable)
	void ReadFile(FString FileName);

	UFUNCTION(BlueprintCallable)
	void WriteToFile(FString FileName, FString Event);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
