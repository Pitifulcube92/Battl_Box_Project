// Fill out your copyright notice in the Description page of Project Settings.


#include "StatSheetActor.h"

// Sets default values
AStatSheetActor::AStatSheetActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	statSheet = NewObject<UStatSheetObject>();
}

// Called when the game starts or when spawned
void AStatSheetActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStatSheetActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStatSheetActor::SetName(const FString name_)
{
	statSheet->SetName(name_);
}

void AStatSheetActor::SetTag(const FString tag_)
{
	statSheet->SetTag(tag_);
}