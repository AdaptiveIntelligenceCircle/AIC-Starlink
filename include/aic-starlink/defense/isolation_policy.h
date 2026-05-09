#pragma once 

#include <string> 

using namespace std; 

namespace aic_starlink :: defense 
{
    struct IsolationPolicy 
    {
        bool enabled = true; 
        double isolate_threshold = 0.85; 
        bool isolate_gateway_first = true; 
    }; 
}