# Threat Model

## 1. Introduction

This document defines the threat model for AIC-Starlink.

AIC-Starlink simulates and analyzes satellite-based communication systems inspired by Starlink-like architectures. Such systems are exposed to hybrid adversaries combining:

- electronic warfare capabilities
- cyber intrusion capabilities
- physical disruption capabilities
- policy-level manipulation strategies

The threat model in AIC-Starlink is intentionally conservative and defensive:  
we assume the attacker is capable, adaptive, and persistent.

---

## 2. Threat Modeling Scope

AIC-Starlink focuses on threats affecting:

- satellite-to-ground link reliability
- terminal behavior and trust
- gateway integrity
- routing stability
- telemetry authenticity
- control plane safety

It does not attempt to model:
- kinetic anti-satellite warfare
- classified satellite payload exploitation
- real-world proprietary Starlink hardware vulnerabilities

---

## 3. Assets to Protect

### 3.1 Communication Availability
- connectivity continuity
- stable routing
- throughput resilience

### 3.2 Integrity of Telemetry
- trustworthy monitoring data
- accurate metrics and logs
- reliable incident classification

### 3.3 Control Plane Safety
- safe routing updates
- safe policy enforcement
- prevention of malicious configuration propagation

### 3.4 User Safety and Compliance
- geo-fencing constraints
- legal compliance policies
- prevention of uncontrolled autonomous escalation

---

## 4. Adversary Model

### 4.1 Adversary Classes

#### A) Electronic Warfare Adversary (EW)
Capabilities:
- jamming uplink/downlink bands
- selective interference on regional beams
- spoofing signal patterns
- forcing packet loss and latency spikes

Goal:
- deny service
- degrade service quality
- cause routing instability

#### B) Cyber Intrusion Adversary
Capabilities:
- telemetry injection
- compromised gateway node
- routing table manipulation attempts
- replaying old telemetry to hide anomalies

Goal:
- bypass detection
- hide malicious actions
- cause misclassification or false alarms

#### C) Insider Adversary
Capabilities:
- policy misconfiguration
- pushing malicious updates
- enabling hidden service denial

Goal:
- targeted disruption
- covert sabotage
- policy-driven censorship

#### D) Hybrid Adversary
Capabilities:
- coordinated EW + cyber manipulation
- disruption combined with stealth telemetry poisoning

Goal:
- maximize impact while minimizing detection probability

---

## 5. Attack Taxonomy

### 5.1 Electronic Warfare Attacks

#### 5.1.1 Wideband Jamming
- high packet loss across a region
- SNR collapse patterns
- broad degradation without clear routing errors

Indicators:
- sudden loss spikes across multiple nodes
- correlated geographically

#### 5.1.2 Narrowband Selective Jamming
- intermittent loss spikes
- targeted disruption to specific terminals/gateways

Indicators:
- isolated node degradation
- repeated periodic disruption

#### 5.1.3 Spoofing / False Signal Injection
- incorrect link state estimation
- routing churn caused by fake signal quality

Indicators:
- impossible link quality changes
- identity mismatch
- inconsistent timing patterns

---

### 5.2 Cyber Attacks

#### 5.2.1 Telemetry Injection
- fake telemetry events inserted into pipeline

Indicators:
- schema anomalies
- out-of-order timestamps
- inconsistent node identifiers

#### 5.2.2 Telemetry Replay Attack
- replay old telemetry to mask an active incident

Indicators:
- repeated patterns
- low entropy sequences
- suspicious timestamp resets

#### 5.2.3 Routing Manipulation Attempt
- force unstable routing selection
- degrade network topology awareness

Indicators:
- abnormal route churn
- non-optimal routing persistence

---

### 5.3 Hybrid Attacks

#### 5.3.1 Jamming + Telemetry Poisoning
- degrade service physically while masking it in telemetry

Indicators:
- mismatch between expected loss and reported loss
- correlation anomalies

#### 5.3.2 Multi-Vector Gateway Attack
- gateway compromise combined with regional jamming

Indicators:
- gateway anomalies + region-wide degradation

---

## 6. Attacker Goals

Attack goals may include:

- **Denial of Service (DoS)**: degrade availability
- **Deception**: hide ongoing attack via telemetry poisoning
- **Escalation**: trigger false defense responses
- **Policy Manipulation**: force geo-fencing / service denial by misclassification
- **Economic Disruption**: degrade reliability to harm trust

---

## 7. Defensive Assumptions

AIC-Starlink assumes defenders can:

- monitor telemetry streams
- maintain baseline metrics
- detect anomalies with limited false positives
- deploy adaptive routing and mitigation
- apply rollback policies safely

However, defenders may not have:
- full visibility into all node internals
- guaranteed integrity of all telemetry
- unlimited bandwidth for redundant rerouting

---

## 8. Security Invariants

The system must enforce:

1. Telemetry validation cannot be bypassed.
2. Policy constraints must override defense automation.
3. Defense actions must be logged and explainable.
4. Rollback must prevent infinite loops.
5. Threat scoring must degrade gracefully under uncertainty.
6. Unknown anomalies must not trigger destructive actions.

---

## 9. Attack Surface Summary

Primary attack surfaces include:

- telemetry ingestion pipeline
- scenario configuration parsing
- plugin integration interface
- event bus adapters
- defense policy execution logic
- file system access for data loading

---

## 10. Research Focus

This threat model supports research into:

- EW anomaly fingerprinting
- telemetry poisoning resilience
- policy-constrained defense automation
- rollback safety and stability
- adversary profile classification
- explainable threat scoring

---

## Conclusion

AIC-Starlink threat modeling treats satellite communication as critical infrastructure exposed to cyber + EW hybrid adversaries. The architecture is built around safe detection and controlled defense response under uncertainty.