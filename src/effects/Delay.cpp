#include "Delay.h"

Delay::Delay() : SoundEffect()
{

    SetId(1); 
    SetParameter("amount", 1.0);

    SetSoundUnitName("Delay");

    tmpReadPtr = 0;
}

void Delay::SetDelayAmount()
{
    *amount = (int) (*parameters)["amount"];

}

OutputData* Delay::ApplyEffect()
{
    printf("SHHHHHHHHHHHHHHHHHH");
    
    // SetDelayAmount();
    *amount = 1;
    
    for (int i=0; i<outputData->size; i++) {
        double y = outputData->outputBuffer[*tmpReadPtr];
        
        outputData->outputBuffer[*tmpReadPtr++] = *amount;
        
        if (*tmpReadPtr >= *amount) { *tmpReadPtr -= *amount; }
    }
    printf("HERHERHERHERHEHRHERHER\n");
    return outputData;
}