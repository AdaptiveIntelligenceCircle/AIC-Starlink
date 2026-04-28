#pragma once 
#include <iostream>

#include <string> 
#include <vector>

using namespace std; 

namespace aic_starlink :: simulation 
{
    struct LatencyResult 
    {
        double latency_ms = 0.0; 
        double jitter_ms = 0.0; 
    }; 

    class LatencyModel
    {
        public:
        LatencyModel() = default;

        void setBaseLatency(double base_ms); 
        void setCongestionFactor(double factor); 
        void setInterferenceFactor(double factor); 

        [[nodiscard]] LatencyResult computeLatency(const vector<string>&path) const; 

        private: 
        double m_base_latency_ms = 20.0; 
        double m_congestion_factor = 1.0; 
        double m_interference_factor = 1.0; 
    }; 
} //namespace aic_starlink :: simulation
