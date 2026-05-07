#pragma once 
using namespace std; 

#include <optional>
#include <string> 

#include "aic-starlink/core/error.h"
#include "aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink :: telemetry
{
    class TelemetryParser 
    {
        public: 
        TelemetryParser() = default; 

        core::Error parseFromJson(const string &json_text, TelemetryEvent &out_event) const; 

        [[nodiscard]] optional<TelemetryEvent> tryParseFromJson(
            const string &json_text
        ) const; 
    }; 
} // namespace aic_starlink :: telemetry..
