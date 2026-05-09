#pragma once 

namespace  aic_starlink :: policy
{
    struct RiskPolicy 
    {
        double medium_threshold = 0.4; 
        double high_threshold = 0.7;
        double critical_threshold = 0.9; 
    };
} // namespace  aic_starlink :: policy
