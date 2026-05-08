#pragma once 

#include <optional>
#include <string>

#include "aic-starlink/telemetry/metrics.h"
#include "aic-starlink/telemetry/telemetry_event.h"

using namespace std; 

namespace aic_starlink :: detection 
{
    struct AnomalyResult 
    {
        bool anomalous = false;
        double score = 0.0; 
        string reason; 
    };  

    class AnomalyDetector 
    {
        public: 
        AnomalyDetector() = default; 

        void setLatencyThreshold(double ms); 
        void setLossThreshold(double loss); 

        [[nodiscard]] AnomalyResult evaluate(const telemetry :: TelemetryEvent &ev, 
        const telemetry :: MetricSummary &baseline) const; 

        private: 
        double m_latency_threshold_ms = 200.0; 
        double m_loss_threshold = 0.2; 
    }; 
} // namespace aic_starlink :: detection