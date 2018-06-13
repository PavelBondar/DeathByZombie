// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	doorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	doorMesh->SetupAttachment(RootComponent);
}

void ADoor::Open()
{
	
	timeLine.PlayFromStart();
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	SetTimelineCallbacks();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timeLine.TickTimeline(DeltaTime);

}

void ADoor::SetTimelineCallbacks()
{
	if (doorOpenCurve)
	{
		UE_LOG(LogTemp, Warning, TEXT("Open"));
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;
		TimelineCallback.BindUFunction(this, FName("ControlDoor"));
		//TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("SetState") });
		timeLine.AddInterpFloat(doorOpenCurve, TimelineCallback);
		//MyTimeline.SetTimelineFinishedFunc(TimelineFinishedCallback);
	}

}

void ADoor::ControlDoor()
{
	float TimelineValue = timeLine.GetPlaybackPosition();
	float CurveFloatValue = rotateSpeed * doorOpenCurve->GetFloatValue(TimelineValue);

	FQuat NewRotation = FQuat(FRotator(0.f, CurveFloatValue, 0.f));

	doorMesh->SetRelativeRotation(NewRotation);
}