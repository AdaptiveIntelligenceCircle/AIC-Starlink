#pragma once 

#include <iostream> 
#include <deque> 

#include "../aic-starlink/telemetry/telemetry_event.h"
using namespace std; 

namespace aic_starlink :: telemetry 
{
    struct MetricSummary 
    {
        double avg_latency_ms = 0.0; 
        double avg_jitter_ms = 0.0; 
        double avg_loss = 0.0; 

        double max_latency_ms = 0.0; 
        double max_loss = 0.0;
         
        size_t samples = 0;
    }; 

    class Metrics 
    {
        public: 
        explicit Metrics(size_t window_size = 100); 

        void ingest(const TelemetryEvent &ev); 

        [[nodiscard]] MetricSummary summarize() const; 
        
        private: 
        size_t m_window_size; 
        deque<LinkMetrics> m_recent; 
    }; 
}