# Governance (AIC-Starlink)

## 1. Purpose

AIC-Starlink is a security-oriented simulation and defense framework focused on modeling resilience and threat response for satellite-based communication networks.

This repository is part of the AIC ecosystem, but is governed as an independent module to ensure:
- clear accountability
- strict security discipline
- long-term maintainability
- stable integration into AIC-Aerospace

---

## 2. Roles

### 2.1 Maintainers
Maintainers are responsible for:
- reviewing and merging pull requests
- managing releases and versioning
- enforcing code quality and security standards
- resolving disputes and design conflicts
- ensuring roadmap alignment

Maintainers have final decision authority on:
- architecture direction
- module boundaries
- security policy enforcement
- acceptance/rejection of contributions

---

### 2.2 Core Contributors
Core contributors are trusted contributors who:
- regularly contribute features, fixes, or documentation
- participate in design discussions
- review PRs when requested

Core contributors may be promoted to Maintainers based on long-term contribution quality and trust.

---

### 2.3 Contributors
Contributors are any individuals who:
- submit PRs
- report issues
- improve documentation
- add tests or scenarios

Contributors do not have merge rights unless promoted.

---

### 2.4 Security Team (Optional Role)
The Security Team is a group of trusted individuals who:
- handle vulnerability reports privately
- coordinate emergency patches
- audit high-risk modules (telemetry, plugin interface, parsers)

The Security Team operates under the rules of [SECURITY.md](SECURITY.md).

---

## 3. Maintainer Model

AIC-Starlink follows a **BDFL-inspired governance model**:

- One primary maintainer (Founder / Lead Architect) holds final decision authority.
- Maintainers act as a council for review, quality control, and operational support.
- Security issues override all other priorities.

This is intentional because the repository targets defense and resilience, where weak governance leads to unsafe outcomes.

---

## 4. Decision Making Process

### 4.1 Normal Decisions
Most decisions are made by:
- discussion in GitHub Issues / Pull Requests
- consensus among maintainers

If consensus cannot be reached, the Lead Maintainer decides.

---

### 4.2 Architectural Decisions (High Impact)
Any change that affects:
- module boundaries
- public API interfaces (`include/`)
- plugin system design
- telemetry schema
- threat scoring logic
- defense policy logic

must be discussed first and documented as an **Architecture Decision Record (ADR)**.

Recommended process:
1. Open a GitHub issue labeled `architecture`
2. Submit proposal document in `docs/`
3. Maintainers review
4. Merge only after approval

---

### 4.3 Security Decisions
Security-related changes always have priority.

For high-risk patches:
- at least 2 maintainer approvals are recommended
- if only 1 maintainer exists, patch must be accompanied by:
  - test coverage
  - reproduction scenario
  - security note in CHANGELOG

---

## 5. Pull Request Review Rules

### 5.1 PR Requirements
A pull request should include:
- clear description of changes
- linked issue reference
- tests or reasoning for why tests are not needed
- documentation updates if API behavior changes

---

### 5.2 Merge Requirements
A PR may be merged only if:
- CI build passes
- tests pass
- code follows `.clang-format`
- no unsafe parsing logic is introduced
- no hidden behavior or obfuscation is present
- telemetry inputs are validated

Maintainers reserve the right to reject PRs that:
- increase attack surface unnecessarily
- introduce complex dependencies
- reduce determinism in simulation

---

### 5.3 Merge Strategy
Default merge strategy:
- **Squash and merge** for clean history
- **Rebase merge** is allowed for maintainers
- direct merges without review are discouraged

---

## 6. Release Process

AIC-Starlink releases follow semantic versioning:

- `MAJOR`: breaking API changes
- `MINOR`: new features, backward compatible
- `PATCH`: bug fixes, security patches

Release checklist:
- update CHANGELOG.md
- tag release in GitHub
- ensure examples compile
- ensure docs reflect current architecture

---

## 7. Deprecation Policy

If an API or module is to be removed:
- mark it as deprecated in documentation
- keep it for at least 1 minor release cycle
- provide migration notes

Immediate removal is allowed only for:
- security reasons
- severe correctness issues

---

## 8. Conflict Resolution

If disagreements occur:
1. attempt discussion in issue thread
2. maintainer mediation
3. final decision by Lead Maintainer

Disruptive or abusive behavior will be handled under [CODE_OF_CONDUCT.md](CODE_OF_CONDUCT.md).

---

## 9. Governance Updates

This governance file may evolve.

Any modification to governance rules requires:
- issue discussion
- maintainer approval
- documentation update

---

## 10. Guiding Principle

AIC-Starlink is built as defensive infrastructure.

**Security, correctness, and responsibility override convenience.**