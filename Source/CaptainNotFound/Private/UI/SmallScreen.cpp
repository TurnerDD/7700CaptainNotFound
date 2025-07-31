#include "UI/SmallScreen.h"
#include "TimerManager.h"

void USmallScreen::StartFuelDrain(float TimeToDrainSeconds)
{
	// Calculate rate so fuel drains from current FuelValue to 0 in TimeToDrainSeconds
	// Each tick: FuelValue -= FuelDrainRate
	// Number of ticks: TimeToDrainSeconds / FuelDrainInterval
	// FuelDrainRate = FuelValue / NumberOfTicks
	FuelDrainRate = FuelValue * FuelDrainInterval / TimeToDrainSeconds;

	if (FuelBar)
	{
		FuelBar->SetPercent(FuelValue);
	}
	GetWorld()->GetTimerManager().SetTimer(
		FuelDrainTimerHandle,
		this,
		&USmallScreen::DrainFuel,
		FuelDrainInterval,
		true
	);
}

void USmallScreen::DrainFuel()
{
	FuelValue -= FuelDrainRate;
	FuelValue = FMath::Clamp(FuelValue, 0.0f, 1.0f);

	if (FuelBar)
	{
		FuelBar->SetPercent(FuelValue);
	}

	if (FuelValue <= 0.0f)
	{
		GetWorld()->GetTimerManager().ClearTimer(FuelDrainTimerHandle);
		OnFuelEnded.Broadcast();
	}
}