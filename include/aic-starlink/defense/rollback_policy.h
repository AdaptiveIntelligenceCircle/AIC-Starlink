#pragma once 

#include <cstdint>

using namespace std;

namespace aic_starlink :: defense 
{
    struct RollbackPolicy 
    {
        bool enabled = true; 

        // Maximum number of rollback attempts allowed.. 
        uint32_t max_rollback = 3; 

        // prevents rollback loops. 
        uint64_t rollback_cooldown = 60; 

        // Only rollback if threat is high enough..
        double rollback_threshold = 0.9; 
    }; 
}