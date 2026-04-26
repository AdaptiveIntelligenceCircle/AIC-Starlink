#!/usr/bin/env bash
set -euo pipefail

# AIC-Starlink Lint Script
# Usage:
#   ./scripts/lint.sh
#
# Requires (optional):
#   clang-tidy, clang-format

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

echo "[AIC-Starlink] Lint started"

if command -v clang-format >/dev/null 2>&1; then
  echo "[AIC-Starlink] Checking clang-format..."
  "${ROOT_DIR}/scripts/format.sh" check
else
  echo "[WARN] clang-format not found. Skipping formatting checks."
fi

if command -v clang-tidy >/dev/null 2>&1; then
  echo "[AIC-Starlink] Running clang-tidy checks..."

  mkdir -p "${BUILD_DIR}"
  cd "${BUILD_DIR}"

  cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

  if [[ ! -f "${BUILD_DIR}/compile_commands.json" ]]; then
    echo "[ERROR] compile_commands.json not found."
    exit 1
  fi

  cd "${ROOT_DIR}"

  FILES=$(find include src tests examples -type f \( -name "*.cpp" -o -name "*.h" \))

  for f in ${FILES}; do
    echo "  [clang-tidy] ${f}"
    clang-tidy "${f}" --quiet --warnings-as-errors="*" \
      -p "${BUILD_DIR}" || exit 1
  done

else
  echo "[WARN] clang-tidy not found. Skipping static analysis."
fi

echo "[AIC-Starlink] Lint finished successfully."