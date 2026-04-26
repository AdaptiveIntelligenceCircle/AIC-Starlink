# `docs/integration_aic.md`

```markdown
# Integration with AIC Ecosystem

## 1. Purpose

This document explains how AIC-Starlink integrates into the broader Adaptive Intelligence Circle (AIC) ecosystem, particularly with AIC-Aerospace.

AIC-Starlink is designed to be:

- a standalone simulation framework
- an embedded defense module for aerospace systems
- a plug-in provider of telemetry analytics and resilience evaluation

---

## 2. Integration Philosophy

AIC-Starlink must remain independently usable.

However, it must expose stable interfaces for integration:

- AIC plugin API contract
- event-driven telemetry ingestion
- JSON-based interoperability mode
- defense action export interface

---

## 3. Integration Modes

### 3.1 Standalone Mode
In standalone mode, AIC-Starlink runs as a self-contained simulator:

Input:
- scenario JSON
- adversary profile JSON
- policy JSON

Output:
- telemetry logs
- threat classification report
- defense action trace

This mode is suitable for:
- demos
- reproducible research
- offline scenario evaluation

---

### 3.2 Embedded Module Mode (AIC-Aerospace)
In embedded mode, AIC-Starlink acts as a module inside AIC-Aerospace.

AIC-Aerospace provides:
- environment state
- mission context
- orbital infrastructure context

AIC-Starlink provides:
- satcom telemetry analytics
- threat scoring
- defense policy suggestions

This mode is suitable for:
- mission-level decision simulation
- aerospace resilience evaluation
- integrated AIC Observatory monitoring

---

### 3.3 Distributed Node Mode
In distributed mode, AIC-Starlink runs as a node inside a distributed AIC network.

It subscribes to telemetry streams and publishes:

- incident alerts
- threat scores
- defense action suggestions

This is suitable for:
- multi-region constellation monitoring
- distributed threat intelligence sharing

---

## 4. Plugin Contract (Recommended)

AIC-Starlink should expose a minimal plugin contract:

### 4.1 Initialization
- initialize context
- load configuration
- load baseline policies

### 4.2 Telemetry Ingestion
- ingest telemetry event
- validate telemetry
- update rolling metrics

### 4.3 Threat Evaluation
- run detectors
- compute threat score
- classify incident

### 4.4 Defense Suggestion
- consult policy engine
- compute response plan
- export defense actions

### 4.5 Shutdown
- flush logs
- export incident reports

---

## 5. Data Exchange Interfaces

### 5.1 JSON API
JSON mode is the most portable integration method.

Supported operations:
- submit telemetry event JSON
- request threat score output JSON
- request defense response output JSON

This mode is recommended for:
- Python integration
- rapid prototyping
- cross-language interoperability

---

### 5.2 Event Bus Integration
Event bus integration supports message-driven architecture.

Event types:
- telemetry update event
- anomaly detected event
- threat classification event
- defense response event

---

## 6. AIC-Aerospace Mapping

AIC-Starlink should map into AIC-Aerospace under:

- `modules/communication/`
- `modules/resilience/`
- `modules/security/`

Aerospace should treat AIC-Starlink as:

- communication resilience provider
- EW/cyber threat analytics engine

---

## 7. Stable API Boundary Rules

To avoid dependency explosion:

- AIC-Aerospace depends only on `include/aic_starlink.h`
- internal headers are not allowed outside AIC-Starlink
- public API must be versioned

---

## 8. Reporting and Logging Integration

AIC-Starlink can export:

- incident reports (JSON)
- threat score summaries
- defense action traces

AIC-Aerospace can ingest these outputs into:

- mission control simulation
- observability dashboards
- strategic policy evaluation modules

---

## Conclusion

AIC-Starlink is designed for standalone usability and clean integration into AIC-Aerospace. The integration model prioritizes stable API boundaries, deterministic reproducibility, and event-driven telemetry processing.