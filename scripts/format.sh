#!/usr/bin/env bash
set -euo pipefail

# AIC-Starlink Format Script
# Usage:
#   ./scripts/format.sh        -> auto format all sources
#   ./scripts/format.sh check  -> verify formatting only

MODE="${1:-apply}"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

if ! command -v clang-format >/dev/null 2>&1; then
  echo "[ERROR] clang-format not found. Install it first."
  exit 1
fi

echo "[AIC-Starlink] Formatting mode: ${MODE}"

FILES=$(find "${ROOT_DIR}/include" "${ROOT_DIR}/src" "${ROOT_DIR}/tests" "${ROOT_DIR}/examples" \
  -type f \( -name "*.cpp" -o -name "*.h" \) 2>/dev/null || true)

if [[ -z "${FILES}" ]]; then
  echo "[WARN] No source files found to format."
  exit 0
fi

if [[ "${MODE}" == "check" ]]; then
  echo "[AIC-Starlink] Checking formatting..."
  BAD=0

  for f in ${FILES}; do
    if ! clang-format --dry-run --Werror "${f}" >/dev/null 2>&1; then
      echo "[FORMAT ERROR] ${f}"
      BAD=1
    fi
  done

  if [[ "${BAD}" -eq 1 ]]; then
    echo "[ERROR] Formatting check failed. Run ./scripts/format.sh to fix."
    exit 1
  fi

  echo "[AIC-Starlink] Formatting check passed."
  exit 0
fi

echo "[AIC-Starlink] Applying formatting..."
for f in ${FILES}; do
  clang-format -i "${f}"
done

echo "[AIC-Starlink] Formatting applied successfully."