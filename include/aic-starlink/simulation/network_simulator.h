#pragma once 
#include <string>

using namespace std; 

#include <cstdint>
#include <optional>
#include <string>
#include <vector>

#include "aic-starlink/simulation/ground_station_model.h"
#include "aic-starlink/simulation/interference_model.h"

#include "aic-starlink/simulation/latency_model.h"
#include "aic-starlink/simulation/link_budget_model.h"

#include "aic-starlink/simulation/routing_model.h"
#include "aic-starlink/simulation/sat-orbit-model.h"
#include "aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink :: simulation
{
    struct SimulationScenario 
    {
        uint64_t seed = 1337; 
        uint64_t start_time = 0; 
        uint64_t end_time = 1000; 
        double time_step = 1.0; 

        string default_region = "GLOBAL"; 
        string source_code = "TERM-01"; 
        string target_node = "GW-01"; 
    };

    class NetworkSimulator 
    {
        public: 
        NetworkSimulator() = default; 

        void setScenario(SimulationScenario scenario); 
        void setOrbitModel(SatOrbitModel latency); 

        void setRoutingModel(RoutingModel routing);
        void setInterferenceModel(InferenceModel interference); 
        void setGroundStationModel(GroundStationModel ground); 
        void setLinkBudgetModel(LinkBudgetModel link_budget); 

        [[nodiscard]] const SimulationScenario &scenario() const noexcept; 
        [[nodiscard]] vector<aic_starlink:: telemetry :: TelemetryEvent> run();

        private: 
        SimulationScenario m_scenario{}; 

        SatOrbitModel m_orbit{};
        LatencyModel m_latency{};
        RoutingModel m_routing{};
        InferenceModel m_interference{};
        GroundStationModel m_ground{};
        LinkBudgetModel m_link_budget{};
    }; 
}