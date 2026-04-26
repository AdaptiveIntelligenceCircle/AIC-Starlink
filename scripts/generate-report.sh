#!/usr/bin/env bash
set -euo pipefail

# AIC-Starlink Report Generator
# Usage:
#   ./scripts/generate_report.sh [Debug|Release]

BUILD_TYPE="${1:-Debug}"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"
REPORT_DIR="${ROOT_DIR}/reports"
TIMESTAMP="$(date +"%Y-%m-%d_%H-%M-%S")"
REPORT_FILE="${REPORT_DIR}/report_${TIMESTAMP}.md"

mkdir -p "${REPORT_DIR}"

echo "[AIC-Starlink] Generating report..."
echo "  Output: ${REPORT_FILE}"

GIT_HASH="unknown"
if command -v git >/dev/null 2>&1; then
  if git -C "${ROOT_DIR}" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    GIT_HASH=$(git -C "${ROOT_DIR}" rev-parse HEAD)
  fi
fi

CLANG_TIDY_STATUS="not installed"
if command -v clang-tidy >/dev/null 2>&1; then
  CLANG_TIDY_STATUS="installed"
fi

CLANG_FORMAT_STATUS="not installed"
if command -v clang-format >/dev/null 2>&1; then
  CLANG_FORMAT_STATUS="installed"
fi

{
  echo "# AIC-Starlink Build Report"
  echo
  echo "**Generated:** ${TIMESTAMP}"
  echo
  echo "## Repository Info"
  echo "- Commit: \`${GIT_HASH}\`"
  echo "- Build Type: \`${BUILD_TYPE}\`"
  echo "- clang-tidy: \`${CLANG_TIDY_STATUS}\`"
  echo "- clang-format: \`${CLANG_FORMAT_STATUS}\`"
  echo
  echo "## System Info"
  echo "\`\`\`"
  uname -a || true
  echo "\`\`\`"
  echo
  echo "## Build Log"
  echo "\`\`\`"
} > "${REPORT_FILE}"

# Build step
{
  "${ROOT_DIR}/scripts/build.sh" "${BUILD_TYPE}" 2>&1
} >> "${REPORT_FILE}"

{
  echo "\`\`\`"
  echo
  echo "## Test Results"
  echo "\`\`\`"
} >> "${REPORT_FILE}"

# Test step
set +e
{
  "${ROOT_DIR}/scripts/run_tests.sh" "${BUILD_TYPE}" 2>&1
} >> "${REPORT_FILE}"
TEST_EXIT_CODE=$?
set -e

{
  echo "\`\`\`"
  echo
  echo "## Test Summary"
  if [[ "${TEST_EXIT_CODE}" -eq 0 ]]; then
    echo "- Status: **PASS**"
  else
    echo "- Status: **FAIL**"
    echo "- Exit Code: ${TEST_EXIT_CODE}"
  fi
  echo
  echo "## Build Artifacts"
  echo "\`\`\`"
} >> "${REPORT_FILE}"

if [[ -d "${BUILD_DIR}" ]]; then
  ls -lah "${BUILD_DIR}" >> "${REPORT_FILE}" || true
fi

{
  echo "\`\`\`"
  echo
  echo "## Notes"
  echo "- This report is generated automatically by AIC-Starlink."
  echo "- Telemetry schema and deterministic simulation requirements must be validated before release."
} >> "${REPORT_FILE}"

echo "[AIC-Starlink] Report generated successfully."
echo "  File: ${REPORT_FILE}"

if [[ "${TEST_EXIT_CODE}" -ne 0 ]]; then
  exit "${TEST_EXIT_CODE}"
fi