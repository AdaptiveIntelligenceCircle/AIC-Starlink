#pragma once 
#include <vector>

#include <iostream>
#include <string>

#include <optional>
#include <cstdint>

using namespace std; 

namespace aic_starlink :: telemetry 
{
    enum class NodeType 
    {
        Satellite, 
        Gateway, 
        Terminal, 
        Unknown 
    };  

    enum class TelemetryEventType 
    {
        LinkMetric, 
        NodeHealth, 
        RoutingUpdate, 
        InterferenceEvent ,
        GatewayCongestion, 
        SecurityAlert, 
        IncidentReport 
    };

    struct NodeIdentity 
    {
        string node_id; 
        NodeType node_type{
            NodeType :: Unknown
        }; 

        string region = "Global";
    };  

    struct LinkMetrics 
    {
        double latency_ms = 0; 
        double jitter_ms = 0; 
        double packet_loss = 0; 

        double snr_db = 0.0; 
        double rssi_dbm = 0.0; 
    }; 

    struct RoutingInfo 
    {
        vector<string>path; 
        double path_cost = 0.0; 
        bool route_change = false; 
    }; 

    struct TelemetryFlags 
    {
        bool simulated = true; 
        bool interference_detected = false; 
        bool suspicious = false; 
    }; 

    struct TelemetryEvent  
    {
        string version = "1.0"; 
        uint64_t timestamp = 0;

        TelemetryEventType event_type {
            TelemetryEventType :: LinkMetric
        }; 

        NodeIdentity source;
        optional<NodeIdentity> target; 

        optional<LinkMetrics> metrics; 
        optional<RoutingInfo> routing; 

        TelemetryFlags flags;
    };  
}