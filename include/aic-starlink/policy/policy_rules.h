#pragma once 

#include <string>
#include <iostream>

#include <unordered_set>
using namespace std; 

namespace aic_starlink :: policy 
{
    struct PolicyRules 
    {
        // Allowed actions globally..
        bool allow_reroute = true; 
        bool allow_isolation = true; 

        bool allow_qos_downgrade = true; 
        bool allow_rollback = true; 

        // Geo-fencing constraints.. 
        unordered_set<string> restricted_regions; 

        // Hard safety constraint.. 
        // never isolate these nodes 
        unordered_set<string> protected_nodes; 

        // if enabled, unknown actions are rejected..
        bool strict_action_whitelist = true; 
    };
}