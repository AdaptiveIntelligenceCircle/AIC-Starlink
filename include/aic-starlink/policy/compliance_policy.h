#pragma once 

#include <string> 
using namespace std; 

namespace aic_starlink:: policy 
{
    class CompliancePolicy 
    {
        public: 
        CompliancePolicy() = default; 

        void setStrictMode(bool strict); 

        [[nodiscard]] bool strictMode() const noexcept; 
        [[nodiscard]] bool allowAction(const string &action_name, const string &region) const; 

        private: 
        bool m_strict = true; 
    }; 
}