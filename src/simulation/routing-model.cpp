#include "../aic-starlink/simulation/routing_model.h"

using namespace std; 

#include <iostream> 
#include <unordered_set>

#include <queue> 
#include <vector> 

namespace aic_starlink :: simulation 
{
    void RoutingModel :: setTopology(
        const unordered_map<string, vector<string>> &graph)
    {
        m_graph = graph;
    }

    RouteDecision RoutingModel :: computeRoute(const string &source, const string &target)
    {
        RouteDecision decision{}; 

        if (m_graph.empty())
        {
            decision.path = {source, target}; 
            decision.path_cost = 1.0; 
            decision.changed = true; 
            return decision; 
        }

        // BFS shortest path(unweighted)

        queue<string> q; 
        unordered_map<string, string> parent; 
        unordered_set<string> visited;  

        q.push(source); 
        visited.insert(source); 

        bool found = false; 

        while (!q.empty())
        {
            auto node = q.front(); 
            q.pop(); 

            if (node == target)
            {
                found = true; 
                break; 
            }

            auto it = m_graph.find(node); 
            if (it == m_graph.end())
            continue; 

            for (const auto &neighbor : it -> second)
            {
                if (visited.contains(neighbor))
                continue; 

                visited.insert(neighbor); 
                parent[neighbor] = node; 
                q.push(neighbor);
            }

            if (!found)
            {
                decision.path = {source, target}; 
                decision.path_cost = 9999.0; 
                decision.changed = true; 
                return decision; 
            }

            // reconstruct path.. 
            vector<string> path;
            string cur = target;
            while (cur != source)
            {
                path.push_back(cur); 
                cur = parent[cur]; 
            }

            path.push_back(source); 

            reverse(path.begin(), path.end()); 

            decision.path = path; 
            decision.path_cost = static_cast<double>(path.size());
            
            string key = source + ">" + target; 
            auto it_last = m_last_routes.find(key); 

            if (it_last == m_last_routes.end())
            {
                decision.changed = true; 
                m_last_routes[key] = path; 
            }
            else 
            {
                decision.changed = (it_last -> second !=path);
                if (decision.changed)
                it_last -> second = path; 
            }
            return decision ; 
        }
    }
}