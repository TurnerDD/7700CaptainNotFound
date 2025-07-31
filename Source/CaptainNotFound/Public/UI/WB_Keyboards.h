#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_Keyboards.generated.h"

UCLASS()
class CAPTAINNOTFOUND_API UWB_Keyboards : public UUserWidget
{
    GENERATED_BODY()

public:
    // Call this from each number button's OnClicked event, passing the digit
    UFUNCTION(BlueprintCallable)
    void OnNumberPressed(int32 Number);

protected:
    // The code sequence to check
    TArray<int32> CodeSequence = { 2, 1, 3, 7 };

    // Current position in the sequence
    int32 CurrentIndex = 0;

    // Called when the correct code is entered
    UFUNCTION(BlueprintImplementableEvent)
    void OnCodeAccepted();

    // Called when the code entry is reset
    UFUNCTION(BlueprintImplementableEvent)
    void OnCodeReset();
};