/** @file VirtualInstrument.h
	@brief Base class for instruments with real-time configurable parameters 
*/
/*
*   This header contains methods for the base class that's inherited to create virtual instruments.
*/

#pragma once

#include "SoundUnit.h"

#include <map>
#include <string>


struct VirtualInstrumentParameter
{
    std::string name;
    float value;
};

class VirtualInstrument : public RawUnit
{
    
    public:
        VirtualInstrument() : RawUnit() { parameters = new std::map<std::string, float>; }
        bool SetParameter(VirtualInstrumentParameter targetParameter);
        bool SetParameter(std::string parameterName, float parameterValue);

    
    protected:
        std::map<std::string, float>* parameters; // this may have to be turned into a pointer

        virtual OutputData* UpdateOutputBuffer() { return outputData; };
        bool AddParameter(VirtualInstrumentParameter targetParameter);


};
