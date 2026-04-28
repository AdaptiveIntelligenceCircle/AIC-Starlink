#pragma once 

#include <cstdint>
#include <optional>

#include <string> 
using namespace std; 

namespace aic_starlink :: core 
{
    struct ModuleConfig 
    {
        // general runtime behavior.. 

        bool deterministic = true; 
        uint64_t random_speed= 1337; 

        // Logging 
        bool enable_logging = true; 
        string log_output_file; 

        // Simulation config..
        bool enable_simulation = true;
        uint32_t simulation_steps = 1000; 
        double simulation_time_step = 1.0; 

        // Telemetry config.. 
        bool enable_telemetry_validation = true; 
        bool enable_metrics_aggregation = true; 

        // Detection Config 
        bool enable_detection = true; 
        bool enable_signature_detection = true; 
        bool enable_anomaly_detection = true; 
        bool enable_behavior_detection = true; 

        // Defense config..
        bool enable_defence_engine = true; 

        // Policy config 
        bool enable_policy_engine = true; 

        // Integration config..
        bool enable_plugin_mode = false; 

        // Optional external config files..
        optional<string> telemetry_schema_path; 
        optional<string> threat_profile_path; 
        optional<string> policy_rules_path; 
        optional<string> scenario_path; 
    }; 

}