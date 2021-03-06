#include "Track.h"

Track::Track()
{
    soundSource = new SoundUnit();
    effectChain = new std::list<SoundEffect>;

    ChangeTrackState(Active);
}

bool Track::AppendNewSoundEffect(BaseEffectPreset* effect)
{
    effectChain->push_back(effect->GetEffect());
    
    printf("New effect appended to: %s\n", GetTrackName().c_str());

    return true;
}

SoundEffect Track::GetEffect(int index)
{
    std::list<SoundEffect>::iterator it = effectChain->begin();
    std::advance(it, index);
    return *it;
}

/* buffer of list[1] = list[0] <- (list[0] is the source of sound and list[1] is an effect)              
* then buffer of list[2] = list[1]
* then buffer of list[3] = list[2]
*  ...
*
* Inside SetOutputBufferData for effects, their effect will be applied and outputdata will be updated.
*/

float Track::GetNextTrackSample()
{
    static float nextSample = 0.0;
    
    printf("::::UNIT CHAIN::::\n");
    printf("Generator: %s\n", soundSource->GetSoundUnitName().c_str());
    
    nextSample = soundSource->GetNextUnitSample(); // first sound unit that generates sounds
    
    effectIt = effectChain->begin();
    
    // // for each sound effect inside the track that comes after the sound generator
    for (effectIt = effectChain->begin(); effectIt != effectChain->end(); ++effectIt) {   

        printf("   Effect: %s\n", effectIt->GetSoundUnitName().c_str());
        
        // printf("before %f\n", nextSample);
        
        nextSample = effectIt->ApplyEffect(nextSample);
        
        // printf("after %f\n", nextSample);

    }
    
    printf("::::::::::::::::::\n");

    return nextSample;
}
