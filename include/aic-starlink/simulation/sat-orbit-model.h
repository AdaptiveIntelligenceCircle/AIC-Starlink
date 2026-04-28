#pragma once 

#include <cstdint>
#include <string>

#include <vector>
using namespace std; 

namespace aic_starlink :: simulation 
{
    struct SatelliteState 
    {
        string satellite_id; 
        double altitude_km = 550.0;

        double inclination_deg = 53.0; 

        // Simplified orbital position parameters..
        double phase = 0.0; 
        double angular_velocity = 1.0; 
    }; 

    class SatOrbitModel 
    {
        public: 
        SatOrbitModel() = default; 

        void setSatellites(vector<SatelliteState> sats); 
        [[nodiscard]] const vector<SatelliteState> &satellites() const noexcept ;

        void step(double dt); 

        [[nodiscard]] bool isVisible(const string &sat_id, const string &ground_region) const; 

        private: 
        vector<SatelliteState> m_satellites;
    }; 
} // namespace aic_starlink:: simulation
