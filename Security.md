# AIC-Starlink Security 

```markdown
# Security Policy (AIC-Starlink)

## 1. Reporting a Vulnerability

If you discover a security vulnerability in AIC-Starlink:

**Do NOT open a public GitHub issue.**

Instead, report it privately to the maintainers.

### Contact
Email: `security@aic.example` *(replace later)*

Include:
- description of the vulnerability
- reproduction steps
- affected file/module
- potential impact
- suggested fix (if available)

---

## 2. Responsible Disclosure

We follow responsible disclosure principles:

- reports are acknowledged within 72 hours
- investigation begins immediately
- fix will be prepared before public disclosure
- public disclosure occurs only when patch is available

---

## 3. Scope of Security Concerns

This repository includes simulation and defensive modeling.

We consider the following as valid security issues:

- memory corruption
- injection vulnerabilities in JSON parsing
- unsafe file operations
- unsafe plugin interfaces
- logic flaws enabling bypass of detection/defense
- misuse that leads to weaponization

---

## 4. Out of Scope

The following are not considered vulnerabilities:

- theoretical attacks without reproducible proof
- denial-of-service on intentionally heavy simulations
- bugs in third-party compilers/libraries

---

## 5. Secure Development Commitment

AIC-Starlink aims to serve as a **defensive infrastructure framework**.

All contributors must follow:
- deterministic simulation safety
- strict validation
- minimal privileges
- no hidden behavior

---

## 6. Security Updates

Security updates will be announced via:
- GitHub Releases
- CHANGELOG.md

Critical issues may trigger emergency releases.