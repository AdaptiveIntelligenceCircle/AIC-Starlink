#pragma once 
#include <iostream>

#include <cstdint>
#include <deque>

#include <optional>
using namespace std; 

#include "aic-starlink/telemetry/telemetry_event.h"

namespace aic_starlink :: telemetry 
{
    class TelemetryCollector 
    {
        public: 
        explicit TelemetryCollector(size_t max_buffer = 10000 ); 
        void push(TelemetryEvent ev); 

        [[nodiscard]] bool empty() const noexcept;
        [[nodiscard]] size_t size() const noexcept;

        [[nodiscard]] optional<TelemetryEvent> pop(); 

        [[nodiscard]] uint64_t lastTimeStamp() const noexcept;
        
        private: 
        deque<TelemetryEvent> m_buffer; 
        size_t m_max_buffer; 
        uint64_t m_last_timestamp = 0; 
    }; 
} // namespace aic-starlink :: telemetry.