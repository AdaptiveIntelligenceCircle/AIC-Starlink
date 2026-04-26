# Roadmap

## Guiding Principle

AIC-Starlink is built as defensive infrastructure.

The roadmap prioritizes:
- correctness
- determinism
- security validation
- modularity
- integration readiness

---

## Phase 0 — Repository Foundation (v0.0.1)
Status: Planned / Initialization

- repository structure finalized
- CMake skeleton working
- basic telemetry schema defined
- base module context and config loader

Deliverable:
- compilation success
- example skeleton builds

---

## Phase 1 — Simulation MVP (v0.1.0)
Status: Core MVP

- network simulator baseline
- latency + packet loss models
- routing model prototype
- interference injection model
- scenario JSON runner
- telemetry output generator

Deliverable:
- reproducible simulation output
- telemetry logs generated for test scenarios

---

## Phase 2 — Telemetry Pipeline (v0.2.0)
Status: Planned

- strict telemetry parser
- validation engine
- rolling metrics engine
- dataset generation tools

Deliverable:
- robust telemetry ingestion and safe parsing

---

## Phase 3 — Detection Engines (v0.3.0)
Status: Planned

- signature detector module
- anomaly detector module
- behavior detector module
- threat candidate output

Deliverable:
- detection accuracy baseline
- test suite for known attack cases

---

## Phase 4 — Threat Intelligence & Scoring (v0.4.0)
Status: Planned

- adversary profile format
- attack taxonomy formalization
- threat scoring model (severity/confidence/persistence)
- incident report generation

Deliverable:
- reproducible incident classification report

---

## Phase 5 — Defense Engine (v0.5.0)
Status: Planned

- reroute policy engine
- QoS downgrade policy
- isolation policy
- rollback policy
- defense trace export

Deliverable:
- end-to-end loop: detect → score → respond

---

## Phase 6 — Integration with AIC-Aerospace (v0.6.0)
Status: Planned

- plugin API stabilization
- event bus adapter
- aerospace adapter
- integration test harness

Deliverable:
- embedded execution inside AIC-Aerospace environment

---

## Phase 7 — Distributed Resilience Mode (v0.7.0)
Status: Planned

- distributed node simulation
- multi-region telemetry synchronization
- federated threat intel sharing

Deliverable:
- distributed constellation resilience experiments

---

## Phase 8 — Research Extensions (v0.8.0+)
Status: Future

Potential expansions:
- Bayesian threat scoring
- RL-based routing adaptation (controlled environment only)
- formal rollback safety verification
- compliance policy framework expansion

---

## Final Goal (v1.0.0)

AIC-Starlink v1.0.0 represents:

- stable telemetry schema
- stable plugin API
- robust simulation + detection + defense pipeline
- reproducible threat evaluation benchmarks
- integration-ready module for AIC-Aerospace

---

## Milestone Definition

A milestone is considered complete only if:

- CI passes
- tests exist for new features
- docs are updated
- example program demonstrates the capability