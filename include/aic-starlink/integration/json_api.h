#pragma once 

#include <string>
using namespace std; 

#include "aic-starlink/core/error.h"
#include "aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink :: integration 
{
    class JsonAPI 
    {
        public: 
        JsonAPI() = default; 

        core :: Error telemetryToJson(const telemetry :: TelemetryEvent &ev, string &out_json) const; 

        core :: Error telemetryFromJson(const string &json_text, telemetry :: TelemetryEvent &out_ev) const; 
    };  
}