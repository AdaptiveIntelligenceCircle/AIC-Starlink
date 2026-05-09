#pragma once 

#include <string> 

#include "aic-starlink/core/error.h"
using namespace std; 

namespace aic_starlink :: integration 
{
    class AerospaceAdapter 
    {
        public: 
        AerospaceAdapter() = default;
        
        core :: Error bindMissionContext(const string &mission_id); 
        core :: Error unbind(); 

        private: 
        string m_mission_id; 
    };
}