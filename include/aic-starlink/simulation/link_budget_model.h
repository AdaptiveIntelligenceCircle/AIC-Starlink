#pragma once 

#include <string> 

using namespace std; 

namespace aic_starlink :: simulation
{
    struct LinkBudgetResult
    {
        double snr_db = 20.0; 
        double rssi_dbm = -70.0; 
        double loss_probability = 0.0; 
    }; 

    class LinkBudgetModel 
    {
        public: 
        LinkBudgetModel() = default; 

        void setNoiseFloor(double noise_floor_db);
        void setBaseSNR(double snr_db); 

        [[nodiscard]] LinkBudgetResult compute(const string &region, double interference_intensity) const; 

        private: 
        double m_noise_floor_db = -90.0;
        double m_base_snr_db = 20.0; 
    }; 
}