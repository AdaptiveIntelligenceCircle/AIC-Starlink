#pragma once

#include <string>

#include "aic-starlink/core/error.h"
#include "aic-starlink/core/module_context.h"
#include "aic-starlink/defense/defense_engine.h"
#include "aic-starlink/detection/threat_scoring.h"
#include "aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink::integration
{
    struct PluginResult
    {
        core::Error error;
        bool success{false};
    };

    struct PluginResponse
    {
        detection::ThreatScore threat_score;
        defense::DefenseDecision defense_decision;
    };

    class AICPluginAPI
    {
      public:
        virtual ~AICPluginAPI() = default;

        virtual PluginResult initialize(core::ModuleContextPtr ctx) = 0;

        virtual PluginResult ingestTelemetry(const telemetry::TelemetryEvent& ev) = 0;

        virtual PluginResult evaluate(PluginResponse& out_response) = 0;

        virtual PluginResult shutdown() = 0;
    };

} // namespace aic_starlink::integration