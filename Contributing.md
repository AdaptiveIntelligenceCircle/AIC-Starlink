# Contributing to AIC-Starlink

Thank you for considering contributing to AIC-Starlink.

This repository is built with a security-first and research-driven mindset. Contributions must prioritize correctness, safety, and clarity.

---

## 1. Contribution Types

We welcome:

- bug fixes
- new simulation models
- detection algorithms
- defense strategies
- policy rule sets
- documentation improvements
- test cases and scenario datasets

---

## 2. Development Principles

All contributions must follow:

- **deterministic simulation**
- **strict input validation**
- **minimal dependencies**
- **secure-by-default design**
- **clear threat modeling assumptions**

---

## 3. Setup

### Build
```bash
mkdir build
cd build
cmake ..
cmake --build . -j
```

### Run Tests 
```bash 
./scripts/run_tests.sh
```
----
## 4. Coding Standards
C++23 standard required
Use .clang-format
Avoid unnecessary dynamic allocations
Prefer RAII and explicit ownership
Never ignore return values silently
All telemetry input must be validated

## 5. Pull Request Process

Before submitting a PR:

Build passes locally
Tests added or updated
Documentation updated if needed
No sensitive data included
No malware, exploit, or weaponized payload

All PRs should reference an issue.

## 6. Commit Style

Use clear commits:

feat: add routing anomaly detector
fix: prevent telemetry overflow
docs: update threat model
test: add jammer scenario case

## 7. Security Contributions

If you discover a vulnerability or security weakness:

Do not open a public issue.
Follow the process in SECURITY.md.

## 8. Contributor Agreement

By contributing, you agree that your contributions may be redistributed under the repository license (GPL-3.0).