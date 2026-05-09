#pragma once 
#include <string>
using namespace std; 

namespace aic_starlink :: policy 
{
    class GeoFencingPolicy 
    {
        public: 
        GeoFencingPolicy() = default; 

        void addRestrictRegion(string region); 
        [[nodiscard]] bool isRestricted(const string &region) const; 

        private: 
        // Internal storage is implemented in src/
        struct Impl;
        Impl *m_impl{
            nullptr
        };
    }; 
}