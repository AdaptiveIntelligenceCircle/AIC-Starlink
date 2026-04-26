# FAQ

## What is AIC-Starlink?

AIC-Starlink is a defensive simulation and resilience framework for satellite-based communication networks inspired by Starlink-like architectures.

It generates telemetry, detects anomalies, scores threats, and suggests defense actions under policy constraints.

---

## Is this related to SpaceX Starlink?

No.  
This project is not affiliated with SpaceX.

The name "Starlink" is used only as a conceptual reference to modern LEO satellite constellation networks.

---

## Is AIC-Starlink a real satellite networking implementation?

No.  
It is a simulation and defense analysis framework.

It does not attempt to replace or replicate proprietary constellation infrastructure.

---

## What is the main output of AIC-Starlink?

Outputs include:

- telemetry logs
- anomaly detection results
- threat classification reports
- defense response traces
- incident reports

---

## Can AIC-Starlink be used for military applications?

This project is designed for defensive resilience research.

However, any usage must respect:
- applicable laws
- compliance constraints
- ethical guidelines

The maintainers do not support offensive weaponization.

---

## How does AIC-Starlink detect attacks?

Through three mechanisms:

- signature-based detection
- behavioral anomaly detection
- statistical anomaly detection

Results are merged into a threat scoring engine.

---

## Does AIC-Starlink support real telemetry input?

Yes, the telemetry schema is designed to accept external input, but strict validation is mandatory.

---

## How is determinism ensured?

- scenario defines a global random seed
- deterministic scheduling is enforced
- simulation does not depend on system time

---

## How does AIC-Starlink integrate with AIC-Aerospace?

AIC-Starlink exposes a plugin interface and can operate as:

- a standalone module
- an embedded subsystem in AIC-Aerospace
- a distributed node in AIC network

See `docs/integration_aic.md`.

---

## Can I contribute?

Yes.  

See `CONTRIBUTING.md`.

Security issues must be reported privately.

See `SECURITY.md`.

---

## What is the long-term goal?

To become a reproducible, auditable, and extensible defensive reference architecture for satellite network resilience.