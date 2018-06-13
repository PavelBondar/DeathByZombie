// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Curves/CurveFloat.h"
#include "Door.generated.h"

UCLASS()
class DEATHBYZOMBIE_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();
	void Open();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

protected:
	UFUNCTION()
	void ControlDoor();

	UPROPERTY(VisibleAnywhere, Category = Door)
	UStaticMeshComponent* doorMesh;

	UPROPERTY(EditAnywhere, Category = Door)
	UCurveFloat* doorOpenCurve;

	UPROPERTY(EditAnywhere, Category = Door)
	float rotateSpeed = 1.0f;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FTimeline timeLine;
	
	void SetTimelineCallbacks();

};
