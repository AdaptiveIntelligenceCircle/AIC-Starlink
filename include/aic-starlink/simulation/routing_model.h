#pragma once 
#include <string>

#include <unordered_map>
#include <vector> 

using namespace std; 

namespace aic_starlink :: simulation
{
    struct RouteDecision
    {
        vector<string> path; 
        double path_cost = 0.0; 
        bool changed = false; 
    }; 

    class RoutingModel
    {
        public:
        RoutingModel() = default;

        void setTopology(const unordered_map<string, vector<string>> &graph); 
        [[nodiscard]] RouteDecision computeRoute(const string &source, const string &target); 

        private: 
        unordered_map<string, vector<string>> m_graph; 
        unordered_map<string, vector<string>> m_last_routes; 
    }; 
}