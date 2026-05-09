#pragma once 

#include <string>
using namespace std; 

namespace aic_starlink :: threat_intel 
{
    enum class AttackCategory 
    {
        None, 
        ElectronicWarfare, 
        CyberAttack, 
        HybridAttack 
    }; 

    struct AttackTaxonomy 
    {
        AttackCategory category
        {
            AttackCategory :: None
        }; 

        string label; 
        string description; 
    };
} // namespace aic_starlink :: threat_intel
