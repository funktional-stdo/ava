/** @file SoundEffect.h
	@brief Base class for sound effect units
*/
/*
*   
*/

#pragma once

#include "VirtualInstrument.h"
#include "SoundEffectType.h"
#include "SoundEffectTypes.h"

#include <map>
#include <string>

class SoundEffect : public VirtualInstrument
{
    public:
        
        SoundEffect();
        SoundEffect(std::string name) : SoundEffect() { SetName(name); }
        
        void ApplyEffect();
        OutputData* UpdateOutputBuffer();

        float GetDryWetValue() { return *drywetValue; }
        bool IsBypassed() { return *isBypassed; }
        
        bool SetDryWetValue(float newVal) { *drywetValue = newVal; return true; }
        bool SetIsBypassed(bool newIsBypassed) { *isBypassed = newIsBypassed; return true; }

        void SetName(std::string name) { SetSoundUnitName(name); SetSoundEffectType(name); }


    private:
        SoundEffectType* effectType;
        SoundEffectTypes* effectCollection;

        float* drywetValue;
        bool* isBypassed;

        void SetSoundEffectType(std::string typeName) { effectType = effectCollection->GetType(typeName); }

};