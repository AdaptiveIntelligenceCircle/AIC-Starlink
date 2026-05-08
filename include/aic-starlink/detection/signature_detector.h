#pragma once 

#include <string>

#include "../aic-starlink/telemetry/telemetry_event.h"
using namespace std; 

namespace aic_starlink :: detection 
{
    enum class SignatureType 
    {
        None,
        JamingPattern, 
        SpoofingPattern, 
        TelemetryInjectionPattern, 
        ReplayPattern 
    }; 

    struct SignatureResult 
    {
        SignatureType type 
        {
            SignatureType :: None
        };

        double confidence = 0.0; 
        string reason; 
    }; 

    class SignatureDetector 
    {
        public:
        SignatureDetector() = default; 

        [[nodiscard]] SignatureResult evaluate(const telemetry :: TelemetryEvent &ev) const; 
    };  
}