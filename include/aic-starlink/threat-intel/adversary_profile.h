#pragma once 

#include <string> 
#include <unordered_map>

using namespace std; 

namespace aic_starlink :: threat_intel 
{
    enum class AdversaryType 
    {
        Unknown, 
        ElectronicWarfare, 
        CyberIntrusion, 
        Insider, 
        Hybrid 
    };

    struct AdversaryProfile 
    {
        string name; 

        AdversaryType type 
        {
            AdversaryType :: Unknown
        }; 

        // Capability scores 0..1 // 
        double jamming_capability = 0.0 ; 
        double spoofing_capability = 0.0; 
        double cyber_injection_capability = 0.0; 

        // optional labels and traits.. 
        unordered_map<string, string> metadata; 
    }; 
}