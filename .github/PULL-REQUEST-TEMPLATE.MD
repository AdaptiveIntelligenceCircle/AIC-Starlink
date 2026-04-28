# Pull Request

## Summary
Describe what this PR changes and why it is needed.

- What problem does it solve?
- What feature does it add?
- What modules are affected?

---

## Type of Change
Select all that apply:

- [ ] Bug fix
- [ ] New feature
- [ ] Refactor / cleanup
- [ ] Documentation update
- [ ] Test update
- [ ] Security fix
- [ ] CI/CD improvement

---

## Related Issue
Link the related issue(s):

- Closes #
- Related to #

---

## Implementation Details
Provide technical details about the implementation:

- Design decisions:
- Trade-offs:
- Performance considerations:
- Determinism considerations (if simulation-related):

---

## Tests
Describe tests performed:

- [ ] Unit tests added/updated
- [ ] Integration tests added/updated
- [ ] Manual test run
- [ ] Simulation scenario verified

Test commands executed:

```bash
./scripts/build.sh Debug
./scripts/run_tests.sh Debug
```
---- 

## Security Checklist
 [ ] No unsafe parsing logic introduced
 [ ] Telemetry validation rules are enforced
 [ ] No sensitive data added (keys, credentials, private telemetry)
 [ ] No weaponized exploit code included
 [ ] Defense actions remain policy-constrained and explainable

## Documentation Checklist
[ ] Docs updated if behavior changed
[ ] Public API documentation updated if include/ changed
[ ] CHANGELOG updated (if required)