#include "../aic-starlink/simulation/ground_station_model.h"

using namespace std; 

#include <algorithm>
#include <cmath>

namespace aic_starlink :: simulation 
{
    void GroundStationModel :: setStations(vector<GroundStation> stations)
    {
        m_stations = move(stations); 
    }

    const vector<GroundStation> &GroundStationModel :: stations() const noexcept 
    {
        return m_stations; 
    }

    double GroundStationModel ::congestionFactor(const string &gateway_id) const 
    {
        auto it = find_if(m_stations.begin(), m_stations.end(), 
        [&](const GroundStation &s)
        {
            return s.gateway_id == gateway_id; 
        }); 

        if (it == m_stations.end())
        return 1.0; 

        // congession factor grows with utilization
        return 1.0 + (it -> utilization * 2.0);
    }
}