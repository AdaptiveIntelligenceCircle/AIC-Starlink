#pragma once

// Main public include for AIC-Starlink.
// Consumers should include this file instead of including internal headers directly.

#include "../aic-starlink/core/starlink-core.h"
#include "../aic-starlink/core/module_context.h"
#include "../aic-starlink/core/module_config.h"
#include "../aic-starlink/core/logger.h"
#include "../aic-starlink/core/error.h"

#include "../aic-starlink/simulation/network_simulator.h"
#include "../aic-starlink/telemetry/telemetry_event.h"
#include "../aic-starlink/detection/threat_scoring.h"
#include "../aic-starlink/defense/defense_engine.h"
#include "../aic-starlink/policy/policy_engine.h"
#include "../aic-starlink/integration/aic_plugin_api.h"