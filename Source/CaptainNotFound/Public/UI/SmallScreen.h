#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "SmallScreen.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFuelEnded);

/**
 * SmallScreen UI widget with a fuel bar that drains over time.
 */
UCLASS()
class CAPTAINNOTFOUND_API USmallScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	// Starts draining fuel over the specified time in seconds
	UFUNCTION(BlueprintCallable)
	void StartFuelDrain(float TimeToDrainSeconds);

	// Delegate called when fuel reaches zero
	UPROPERTY(BlueprintAssignable)
	FOnFuelEnded OnFuelEnded;

protected:
	// Reference to the FuelBar ProgressBar (bind in UMG designer)
	UPROPERTY(meta = (BindWidget))
	UProgressBar* FuelBar;

	// Current fuel value (0.0 - 1.0)
	float FuelValue = 0.75;

	// Timer handle for draining
	FTimerHandle FuelDrainTimerHandle;

	// Rate at which fuel drains per tick
	float FuelDrainRate = 0.01f;

	// Interval between drain ticks (seconds)
	float FuelDrainInterval = 0.1f;

	// Called every tick to drain fuel
	void DrainFuel();
};