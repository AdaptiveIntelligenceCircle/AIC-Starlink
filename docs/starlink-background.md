# Starlink Background (Context for AIC-Starlink)

## 1. Purpose

This document provides background context for satellite internet constellations inspired by Starlink-like architectures.

It is not intended to describe proprietary details of SpaceX Starlink.  
Instead, it provides high-level system characteristics required to justify the design assumptions of AIC-Starlink.

---

## 2. Satellite Internet Constellations

A satellite internet constellation typically consists of:

- a large number of low Earth orbit (LEO) satellites
- user terminals (ground dish / phased-array antennas)
- ground gateways connected to terrestrial fiber networks
- a network control plane responsible for routing and orchestration

The primary objective is to provide global broadband access.

---

## 3. Key Characteristics of LEO Networks

### 3.1 Dynamic Topology
Unlike terrestrial networks, satellite constellations have constantly changing topology:

- satellites move quickly relative to ground terminals
- links appear/disappear due to visibility windows
- routing paths are continuously recalculated

This implies frequent handoffs and dynamic routing decisions.

---

### 3.2 Latency and Jitter Patterns
LEO networks provide lower latency than geostationary satellites, but still show:

- latency variance depending on route path
- congestion effects at gateways
- jitter introduced by dynamic routing transitions

---

### 3.3 Link Budget Constraints
Signal quality depends on:

- distance and orbital position
- atmospheric attenuation
- rain fade and environmental noise
- interference sources

Link budgets influence throughput and packet loss probability.

---

### 3.4 Gateway Dependency
Although satellites form a mesh, gateways remain a critical dependency:

- they connect satellite traffic to terrestrial internet
- they are regional choke points
- they may enforce geo-fencing policies

---

## 4. Security and Resilience Challenges

Satellite networks face unique security challenges:

- jamming and spoofing can degrade physical layer integrity
- terminal compromise may create botnet-like behavior
- telemetry injection can hide or fabricate incidents
- policy enforcement can be abused to censor or deny service
- control plane errors can propagate widely

Because of scale, manual operations are not sufficient.

---

## 5. Fault Detection, Isolation, and Recovery (FDIR)

In aerospace engineering, FDIR refers to:

- detecting faults or anomalies
- isolating faulty components
- recovering by rerouting or rollback

AIC-Starlink is conceptually aligned with FDIR, but extended to cyber + EW threat scenarios.

---

## 6. Why AIC-Starlink Uses Abstractions

AIC-Starlink intentionally avoids proprietary implementations.

Instead, it focuses on abstract models:

- orbit visibility models (simplified)
- routing graph dynamics
- link degradation under interference
- telemetry-driven anomaly detection

This abstraction is sufficient for research-grade resilience evaluation.

---

## Conclusion

Starlink-like constellations represent a new class of critical infrastructure with dynamic topology and strong exposure to EW/cyber threats. AIC-Starlink exists to model these systems defensively in a reproducible and extensible framework.