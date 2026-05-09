#pragma once 
#include <string>

using namespace std; 

namespace aic_starlink:: defense 
{
    struct ReroutePolicy
    {
        bool enabled = true; 
        double max_reroute_cost = 2.0; 
        bool prefer_low_latency = true; 
        bool avoid_suspicious_nodes = true; 
    }; 
}