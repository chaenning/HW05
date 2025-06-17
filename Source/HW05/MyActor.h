// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW05_API AMyActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultRoot;
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	void Move();
	int32 Step();
	void CreateEvent();
	float Distance(FVector prevPos, FVector nowPos);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	FVector Start = FVector(0, 0, 0);

	int32 EventCnt = 0;
	float TotalDistance = 0.0f;
};
