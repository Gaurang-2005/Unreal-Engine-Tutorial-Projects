// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerArea.h"

UTriggerArea::UTriggerArea() {
	PrimaryComponentTick.bCanEverTick = true;
    UE_LOG(LogTemp, Display, TEXT("Constructing!!!"));
}

void UTriggerArea::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Display, TEXT("Trigger Component Alive!"));


}

void UTriggerArea::SetMover(UMover* NewMover) {
    Mover = NewMover;
}


void UTriggerArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    AActor* Actor = UTriggerArea::GetAcceptableActor();
    if (!Actor) {
        Mover->SetShouldMove(false);
    }
    else {
        UPrimitiveComponent* Component = Cast<UPrimitiveComponent> (Actor->GetRootComponent());
        if (Component) {
            Component->SetSimulatePhysics(false);
        }
        Actor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
    }
}

AActor* UTriggerArea::GetAcceptableActor() const {
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor* Actor : Actors) {
        if (Actor->ActorHasTag(AcceptableActorTag) && !Actor->ActorHasTag("Grabbed")) {
            return Actor;
        }
    }

    return nullptr;
}

