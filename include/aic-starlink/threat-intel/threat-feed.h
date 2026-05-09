#pragma once 

#include <optional>
#include <string>

#include "aic-starlink/core/error.h"
#include "aic-starlink/threat-intel/adversary_profile.h"

using namespace std; 

namespace aic_starlink :: threat_intel 
{
    class ThreatFeed 
    {
        public: 
        ThreatFeed() = default;
        
        core :: Error loadFromFile(const string &path); 
        [[nodiscard]] optional<AdversaryProfile> currentProfile() const; 

        private: 
        optional<AdversaryProfile> m_profile; 
    }; 
}