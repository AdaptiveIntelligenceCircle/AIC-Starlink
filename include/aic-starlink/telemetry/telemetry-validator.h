#pragma once 

#include <cstdint>
using namespace std; 

#include "aic-starlink/core/error.h"
#include "aic-starlink/telemetry/telemetry-parser.h"

namespace aic_starlink :: telemetry 
{
    struct TelemetryValidationConfig
    {
        bool strict_schema = true; 
        bool enforce_monotonic_time = true; 

        uint64_t allowed_time_skew = 0; 
    };  

    class TelemetryValidator 
    {
        public: 
        TelemetryValidator() = default; 

        void setConfig(TelemetryValidationConfig cfg);
        core :: Error validate(const TelemetryEvent &ev, uint64_t last_timestamp = 0); 
        
        private: 
        TelemetryValidationConfig m_cfg{}; 
    }; 
}