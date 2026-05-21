#include "../aic-starlink/simulation/link_budget_model.h"

using namespace std; 

#include <algorithm>

namespace aic_starlink :: simulation 
{
    void LinkBudgetModel :: setNoiseFloor(double noise_floor_db)
    {
        m_noise_floor_db = noise_floor_db; 
    }

    void LinkBudgetModel :: setBaseSNR(double snr_db)
    {
        m_base_snr_db = snr_db; 
    }

    LinkBudgetResult LinkBudgetModel:: compute(const string &region, double interference_intensity) const noexcept  
    {
        (void) region; 

        LinkBudgetResult r{};

        r.snr_db = m_base_snr_db - (interference_intensity *20.0); 
        r.rssi_dbm = m_noise_floor_db+ r.snr_db; 

        // loss probability increases when SNR decreases.. 
        double loss = 0.0;
        if (r.snr_db < 5.0)
            loss = 0.4;
        else if (r.snr_db < 10.0)
            loss = 0.2;
        else if (r.snr_db < 15.0)
            loss = 0.1;
        else
            loss = 0.01;

        // add interference-based scaling
        loss = std::min(1.0, loss + interference_intensity * 0.3);
        r.loss_probability = loss;

        return r;
    }
}