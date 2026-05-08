#pragma once 
#include <string>

#include <iostream>
#include "../aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink :: detection
{
    struct BehaviorResult 
    {
        bool suspicious = false; 
        double score = 0; 
        string reason; 
    };
    
    class BehaviorDetector 
    {
        public: 
        BehaviorDetector() = default;

        void setMaxRouteChurn(double churn_rate); 

        [[nodiscard]] BehaviorResult evaluate(const telemetry :: TelemetryEvent &ev) const; 

        private: 
        double m_max_route_churn = 0.4 ; 
    };
}