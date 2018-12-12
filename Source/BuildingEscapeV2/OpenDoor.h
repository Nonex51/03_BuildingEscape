// Copyright by SIBOT Guillaume

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"

//Forward declare afin de pouvoir declarer un pointer mais ne permet pas de la manipuler.
class ATriggerVolume;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BUILDINGESCAPEV2_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Something")
		float OpenAngle = 90.f;

	//Tu peux mettre BlueprintReadOnly, si tu veux simplement pouvoir le get en Blueprint et non le set
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Something")
		ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Something")
		float DoorCloseDelay = 0.7f;

		float LastDoorOpenTime;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();



public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	//Pas besoin de forward declare un AActor vu qu'il est déjà inclue dans CoreMinimal.h
	//AActor* PressurePlate; //remember pawn inherits from actor
	AActor* ActorThatOpens;
	AActor* Owner; // the Owning door
};