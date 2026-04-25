# Changelog

All notable changes to this project will be documented in this file.

This format is based on **Keep a Changelog**  
and this project adheres to **Semantic Versioning**.

---

## [Unreleased]

### Added
- Initial repository structure for AIC-Starlink.
- Simulation framework architecture (orbit abstraction, latency, routing).
- Telemetry ingestion pipeline (parser, validator, metrics extraction).
- Threat detection modules (signature + anomaly detection).
- Defense engine foundation (reroute, isolation, rollback policies).
- Threat intelligence structures (adversary profile, taxonomy).
- Integration layer design (AIC plugin interface + event bus adapter).
- Documentation scaffolding (`docs/overview.md`, `docs/architecture.md`).

### Changed
- N/A

### Deprecated
- N/A

### Removed
- N/A

### Fixed
- N/A

### Security
- Introduced security-first governance and responsible disclosure policy.

---

## [0.1.0] - YYYY-MM-DD

### Added
- Initial public release of AIC-Starlink.
- Base simulation models:
  - latency model
  - packet loss model
  - interference model
- Base telemetry event schema.
- Basic anomaly detector prototype.
- Defense response demo scenario.
- Example programs and test scaffolding.
- Project governance and security policy files.

### Changed
- N/A

### Fixed
- N/A

### Security
- Added strict telemetry validation requirements.
- Established secure plugin interface rules.

---

## [0.0.1] - YYYY-MM-DD

### Added
- Project initialization.
- Build system skeleton (CMake).
- Core module skeleton (`starlink_core`).

### Security
- Added baseline secure development rules.