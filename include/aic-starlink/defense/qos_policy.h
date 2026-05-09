#pragma once 

namespace aic_starlink :: defense 
{
    struct QoSPolicy 
    {
        bool enabled = true; 
        double downgrade_threshold = 0.7; 
        double min_bandwidth_ratio = 0.3; 
    }; 
}