#pragma once 

#include <string> 

#include "anomaly-detector.h"
#include "behavior_detector.h"
#include "signature_detector.h"

using namespace std; 

namespace aic_starlink :: detection 
{
    enum class ThreatLevel 
    {
        Low, 
        Medium, 
        High, 
        Critical
    }; 

    struct ThreatScore 
    {
        ThreatLevel level
        {
            ThreatLevel :: Low
        };

        double severity = 0.0; 
        double confidence = 0.0; 
        double persistence = 0.0; 
        double blast_radius = 0.0; 

        string portable_attack; 
        string explaination; 
    }; 

    class ThreatScoring 
    {
        public: 
        ThreatScoring() = default; 

        [[nodiscard]] ThreatScore compute(const AnomalyResult &anomaly, 
        const SignatureResult &signature, 
        const BehaviorResult &behavior) const; 
    }; 
} // namespace aic_starlink :: detection