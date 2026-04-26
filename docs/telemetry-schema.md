# Telemetry Schema

## 1. Purpose

This document defines the telemetry schema used in AIC-Starlink.

Telemetry represents the core observational signal for:

- anomaly detection
- threat scoring
- defense orchestration
- incident reporting

Telemetry is treated as hostile input and must always be validated.

---

## 2. Telemetry Event Model

Telemetry events are represented as structured objects.

A telemetry event contains:

- metadata (timestamp, node identity)
- link metrics (loss, latency, jitter, signal quality)
- routing metrics
- optional security markers
- optional simulation tags

---

## 3. Canonical JSON Format

Example telemetry event:

```json
{
  "version": "1.0",
  "timestamp": 1710001000,
  "event_type": "LINK_METRIC",
  "source": {
    "node_id": "SAT-102",
    "node_type": "SATELLITE",
    "region": "EU-NORTH"
  },
  "target": {
    "node_id": "GW-03",
    "node_type": "GATEWAY"
  },
  "metrics": {
    "latency_ms": 42.1,
    "jitter_ms": 3.5,
    "packet_loss": 0.01,
    "snr_db": 18.7,
    "rssi_dbm": -72.4
  },
  "routing": {
    "path": ["SAT-102", "SAT-088", "GW-03"],
    "path_cost": 57.3,
    "route_change": false
  },
  "flags": {
    "simulated": true,
    "interference_detected": false
  }
}

```

---- 

## 4. Telemetry Event Types

Supported event types include:

**LINK_METRIC**
**NODE_HEALTH**
**ROUTING_UPDATE**
**INTERFERENCE_EVENT**
**GATEWAY_CONGESTION**
**SECURITY_ALERT**
**INCIDENT_REPORT**

## 5. Mandatory Fields

All telemetry events must contain:

+ version
+ timestamp
+ event_type
+ source.node_id
+ source.node_type
+ metrics (optional depending on event type)

## 6. Validation Rules

Telemetry validation must enforce:

6.1 Schema Validation
required fields must exist
no unexpected type mismatch

6.2 Timestamp Constraints
timestamps must be monotonic (configurable tolerance)
timestamps must be within scenario time window

6.3 Numeric Bounds
latency_ms >= 0
packet_loss must be between [0.0, 1.0]
snr_db must be within plausible ranges
jitter must be non-negative

6.4 Identity Validation
node_id must match known nodes in context
node_type must be valid enum
region must match allowed region labels

6.5 Routing Sanity
routing path must be valid node chain
no impossible cycles unless explicitly allowed

## 7. Metrics Definitions
7.1 Latency

Round-trip or one-way latency depending on scenario config.

7.2 Jitter

Variance of latency over a sliding window.

7.3 Packet Loss

Observed packet drop probability over a defined interval.

7.4 SNR / RSSI

Simplified physical layer indicators.

## 8. Derived Metrics

AIC-Starlink computes derived metrics:

moving average latency
loss spike detection
jitter entropy
route churn rate
node trust stability score

## 9. Telemetry Integrity Risks

Telemetry may be manipulated by:

injection
replay
schema poisoning
metric corruption
timestamp tampering

Thus:

validation is mandatory
anomaly detection must detect telemetry manipulation itself

## 10. Versioning Strategy

Telemetry schema uses semantic versioning.

minor version changes are backward compatible
major changes require parser updates and explicit version bump
Conclusion

Telemetry schema in AIC-Starlink is a security-critical interface. It is strictly validated and versioned to support reproducible research and safe defense decision-making.