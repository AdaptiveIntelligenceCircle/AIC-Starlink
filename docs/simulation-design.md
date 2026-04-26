# Simulation Design

## 1. Purpose

This document defines how the simulation layer in AIC-Starlink is designed.

The simulator does not aim for full physical accuracy.  
It aims for structured realism that supports:

- deterministic reproducibility
- scalable experimentation
- adversary modeling
- telemetry generation

---

## 2. Simulation Model Philosophy

AIC-Starlink simulation is based on:

- **graph-based topology modeling**
- **parameterized probabilistic link behavior**
- **time-step iteration**
- **scenario-driven adversary activation**

Simulation is designed to output telemetry events that mimic operational network monitoring.

---

## 3. Simulation Entities

### 3.1 Satellite Node
Represents a satellite object with properties:

- unique ID
- orbital state (abstracted)
- link endpoints
- health state
- capacity constraints

### 3.2 Gateway Node
Represents a ground gateway with properties:

- geographic region
- capacity limit
- congestion factor
- trust score

### 3.3 Terminal Node
Represents a user terminal:

- mobility state (optional)
- trust score
- connectivity preferences
- traffic class (consumer / enterprise / defense)

---

## 4. Topology Graph Model

The network is represented as a dynamic graph:

- nodes: satellites, gateways, terminals
- edges: links with quality parameters

Edges contain:

- latency baseline
- jitter distribution
- packet loss probability
- bandwidth capacity
- interference multiplier

Routing uses this graph to compute paths.

---

## 5. Time Model

Simulation runs in discrete time steps:

- `t0 ... tn`
- each step updates satellite positions, link states, and routing decisions

Time step granularity is configurable via scenario file.

---

## 6. Orbit Abstraction

Orbit is abstracted as:

- periodic visibility windows between satellites and ground terminals
- adjacency between satellites determined by simplified proximity rules

This provides:
- dynamic link availability
- realistic handoff behavior
- controlled complexity

---

## 7. Latency Model

Latency is computed as:
> latency = base_distance_latency + congestion_penalty + interference_penalty

Where:
- base latency is derived from route length
- congestion penalty is derived from gateway utilization
- interference penalty is derived from jamming intensity

Jitter is introduced as a bounded random variable.

---

## 8. Packet Loss Model

Packet loss probability is computed as:

- baseline loss probability
- increased loss under interference
- increased loss under congestion

Loss can be correlated across multiple nodes for region-wide jamming simulation.

---

## 9. Interference and Attack Injection

Interference is modeled through an `InterferenceModel` which can inject:

- jamming intensity patterns
- spoofing events (fake link quality)
- targeted disruptions on specific nodes

Attack patterns can be:

- constant
- periodic
- adaptive (reacting to defense actions)

---

## 10. Scenario Input Design

Scenario files define:

- seed value
- satellite count and abstract orbit settings
- terminal count and distribution
- gateway distribution and capacity
- baseline traffic patterns
- adversary activation profiles
- simulation duration and time step size

---

## 11. Telemetry Generation

Simulation outputs telemetry events:

- link metrics (SNR, RSSI approximations)
- packet loss observations
- latency/jitter measurements
- routing decision traces
- interference flags
- node health state

Telemetry is exported in JSON format or directly passed into telemetry pipeline.

---

## 12. Determinism Guarantees

Simulation determinism requires:

- global PRNG seed
- deterministic scheduling of events
- deterministic iteration order for nodes and edges

No simulation behavior may depend on system time.

---

## 13. Output Artifacts

Simulation produces:

- telemetry event stream
- metrics report (optional)
- incident trace logs (optional)
- defense response trace (when defense engine is enabled)

---

## Conclusion

AIC-Starlink simulation is a deterministic graph-based environment for studying satcom resilience under adversarial conditions. It is designed for research reproducibility and integration with telemetry-driven detection and defense modules.