#pragma once 

#include <string> 
using namespace std; 

#include "defense_engine.h"
#include "policy_rules.h"

namespace aic_starlink :: policy 
{
    class PolicyEngine 
    {
        public: 
        PolicyEngine() = default; 

        void setRules(PolicyRules rules); 

        [[nodiscard]] const PolicyRules &rules() const noexcept; 
        [[nodiscard]] bool allow(const defense :: DefenseAction &action, const string &region) const;
        
        private: 
        PolicyRules m_rules{}; 
    }; 
}

