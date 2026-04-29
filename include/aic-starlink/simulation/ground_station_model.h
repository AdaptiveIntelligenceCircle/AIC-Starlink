#pragma once

#include <string>
#include <vector>

namespace aic_starlink::simulation
{
    struct GroundStation
    {
        std::string gateway_id;
        std::string region;
        double capacity_mbps{1000.0};
        double utilization{0.0}; // 0..1
    };

    class GroundStationModel
    {
      public:
        GroundStationModel() = default;

        void setStations(std::vector<GroundStation> stations);
        [[nodiscard]] const std::vector<GroundStation>& stations() const noexcept;

        [[nodiscard]] double congestionFactor(const std::string& gateway_id) const;

      private:
        std::vector<GroundStation> m_stations;
    };

} // namespace aic_starlink::simulation