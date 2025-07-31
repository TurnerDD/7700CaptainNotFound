#include "UI/WB_Keyboards.h"

void UWB_Keyboards::OnNumberPressed(int32 Number)
{
    if (CodeSequence.IsValidIndex(CurrentIndex) && Number == CodeSequence[CurrentIndex])
    {
        CurrentIndex++;
        if (CurrentIndex == CodeSequence.Num())
        {
            // Code accepted
            OnCodeAccepted();
            CurrentIndex = 0; // Reset for next entry
        }
    }
    else
    {
        // Wrong input, reset
        CurrentIndex = 0;
        OnCodeReset();
    }
}