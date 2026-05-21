#include "../aic-starlink/simulation/interference_model.h"

using namespace std; 

namespace aic_starlink :: simulation 
{
    void InferenceModel :: setEvent(InteferenceEvent ev)
    {
        m_event = move(ev); 
    }

    const InteferenceEvent &InferenceModel :: event() const noexcept
    {
        return m_event; 
    }

    bool InferenceModel :: active(uint64_t timestamp) const noexcept 
    {
        if (m_event.type == InferenceType :: None)
        {
            return false; 
        }

        return timestamp >= m_event.start_time and timestamp <= m_event.end_time;
    }

    double InferenceModel :: lossMultiplier(uint64_t timestamp, const string &region) const 
    {
        if (!active(timestamp))
        return 1.0; 

        if (!m_event.region.empty() and m_event.region != region)
        return 1.0 ;

        // wideband jamming is more impactful.. 
        double base = 1.0 + m_event.intensity * 5.0; 

        if (m_event.type == InferenceType :: NarrowbandJamming)
        base = 1.0 + m_event.intensity * 2.0; 

        return base ; 
    }
}