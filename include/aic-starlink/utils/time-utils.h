#pragma once 

#include <cstdint>

using namespace std; 

namespace aic_starlink :: utils 
{
    class TimeUtils 
    {
        public:
        [[nodiscard]] static uint64_t nowEpochSeconds(); 
    }; 
} // namespace aic_starlink :: utils 