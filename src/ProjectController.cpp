#include "ProjectController.h"

ProjectController::ProjectController()
{
    globalSettings.PROJECT_SAMPLE_RATE = 44100;
    globalSettings.PROJECT_NAME = "PURE AVA";

    tracks = new std::list<Track>;

    Track mainTrack ("Main Track");
    tracks->push_back(mainTrack);

}

bool ProjectController::AppendTrack(Track newTrack)
{
    tracks->push_back(newTrack);
    return true;
}

bool ProjectController::AppendTrack()
{
    Track newTrack;
    
    std::string newTrackName = "Track " + std::to_string(tracks->size()+1);
    newTrack.SetTrackName(newTrackName);
    
    newTrack.ChangeTrackState(Active);

    tracks->push_back(newTrack);
    
    return true;
}

Track* ProjectController::GetTrack(int trackIndex)
{
    std::list<Track>::iterator it = tracks->begin();
    std::advance(it, trackIndex);
    return &(*it);
}

int ProjectController::GetNumActiveTracks()
{

    int ans = 0;
    for (std::list<Track>::iterator it = tracks->begin(); it != tracks->end(); ++it) {

        if(it->GetTrackState() == Active)
            ans++;
    }

    return ans;
}

float ProjectController::GetNextProjectSample()
{
    static float outputSample = 0.0;
    outputSample = 0.0;
    static float trackOutputData = 0.0;
    
    float bufferDivisionValue = GetDivisionValue((int) GetNumActiveTracks()); // divide the buffer and sum up the data on all tracks using this value
    
    static std::list<Track>::iterator trackIterator = tracks->begin();
    for (trackIterator = tracks->begin(); trackIterator != tracks->end(); ++trackIterator) { // for each track

        // printf("\n======= Track: %s =======\n", trackIterator->GetTrackName().c_str());
        
        if (trackIterator->GetTrackState() == Active) // only calculate the buffer based on active tracks
        {

            trackOutputData = trackIterator->GetNextTrackSample();            
            
            outputSample += bufferDivisionValue * trackOutputData; // update the buffer value based on the division value

        }
        else
        {
            printf("^^^^ Track was not active.\n");
            continue;
        }
    }
    return outputSample;

}
