/** @file SoundEffectType.h
	@brief defines a sound effect behavior (sound algorithm).
*/
/**
 * This class is a base class that is inherited by classes inside the effects/ directory.
 * These objects are used inside SoundEffect class to indicate the behavior of a sound effect.
 */


#pragma once

#include "AudioDataStructs.h"

#include <map>


class SoundEffectType
{
    public:
        SoundEffectType()
        { 
            outputData = (struct OutputData*) malloc (sizeof(struct OutputData));
            InitOutputDataStruct(outputData);
        }
         
        virtual float ApplyEffect(std::map<std::string, float>* parameters, float inputSample) { return 0.0; }
    
    protected:
        OutputData* outputData;
        
        
}; 