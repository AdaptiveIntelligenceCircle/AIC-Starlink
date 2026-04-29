#pragma once 

#include <cstdint>
#include <string>

using namespace std; 

namespace aic_starlink :: simulation
{
    enum class InferenceType
    {
        None, 
        WidebandJamming, 
        NarrowbandJamming, 
        Spoofing, 
        NoiseInjection 
    };  

    struct InteferenceEvent
    {
        InferenceType type {
            InferenceType :: None
        };

        string region;
        double intensity = 0.0; 
        uint64_t start_time = 0; 
        uint64_t end_time = 0; 
    };

    class InferenceModel 
    {
        public: 
        InferenceModel() = default;

        void setEvent(InteferenceEvent ev); 
        [[nodiscard]] const InteferenceEvent&event() const noexcept; 

        [[nodiscard]] bool active(uint64_t timestamp) const noexcept; 

        [[nodiscard]] double lossMultiplier(uint64_t timestamp, const std::string& region) const;
        [[nodiscard]] double latencyMultiplier(uint64_t timestamp, const std::string& region) const;

        private:
        InteferenceEvent m_event{};
    };
}