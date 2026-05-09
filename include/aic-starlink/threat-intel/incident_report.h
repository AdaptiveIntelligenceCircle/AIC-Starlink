#pragma once 
using namespace std; 

#include <cstdint>
#include <string> 
#include <vector> 

#include "aic-starlink/defense/defense_engine.h"
#include "aic-starlink/detection/threat_scoring.h"

namespace aic_starlink :: threat_intel 
{
    struct IncidentReport 
    {
        uint64_t timestamp = 0; 
        string incident_id ; 
        string region; 

        detection :: ThreatScore threat_score; 
        vector<defense::DefenseAction> actions;

        string narrative; 
    }; 
}
