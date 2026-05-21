#include "../aic-starlink/simulation/latency_model.h"

using namespace std; 

#include <cmath> 

namespace aic_starlink :: simulation 
{
    void LatencyModel :: setBaseLatency(double base_ms)
    {
        m_base_latency_ms = base_ms; 
    }

    void LatencyModel :: setCongestionFactor(double factor)
    {
        m_congestion_factor = factor; 
    }

    void LatencyModel :: setInterferenceFactor(double factor)
    {
        m_interference_factor = factor; 
    }

    LatencyResult LatencyModel :: computeLatency(const vector<string> &path) const 
    {
        const double hops = static_cast<double> (path.size() > 0 ? path.size() - 1:0);
        const double base = m_base_latency_ms + hops *5.0; 

        double latency = base *m_congestion_factor *m_interference_factor;

        // jitter as a bounded function of interference 
        double jitter = min(50.0, latency *0.05 *(m_interference_factor)); 

        return LatencyResult{
            latency, jitter
        };
    }
}