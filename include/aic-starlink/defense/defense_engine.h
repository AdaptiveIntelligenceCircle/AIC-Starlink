#pragma once 

#include <string> 
#include <vector>

#include "aic-starlink/core/error.h"
#include "aic-starlink/detection/threat_scoring.h"

using namespace std; 

namespace aic_starlink :: defense 
{
    enum class DefenseActionType 
    {
        None, 
        RerouteTraffic, 
        DowngradeQoS, 
        IsolateNode, 
        RollbackConfig, 
        EnableRedundancyNode, 
        AlertUpstream 
    }; 

    struct DefenseAction 
    {
        DefenseActionType type {
            DefenseActionType :: None
        };

        string target; 
        string reason; 
        double priority = 0.0; 
    }; 

    struct DefenseDecision 
    {
        bool action_required = false;
        vector<DefenseAction> actions; 
        string summary; 
    };  

    class DefenseEngine 
    {
        public: 
        DefenseEngine() = default; 

        [[nodiscard]] DefenseDecision decide(const detection :: ThreatScore &score) const; 

        private:
        [[nodiscard]] DefenseDecision decideCritical(const detection :: ThreatScore &score) const; 
        [[nodiscard]] DefenseDecision decideHigh(const detection :: ThreatScore &score) const; 
    };  
}  // namespace aic_starlink :: defense