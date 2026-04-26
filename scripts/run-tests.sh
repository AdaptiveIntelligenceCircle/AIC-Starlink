#!/usr/bin/env bash
set -euo pipefail

# AIC-Starlink Test Runner
# Usage:
#   ./scripts/run_tests.sh [Debug|Release]
#
# Example:
#   ./scripts/run_tests.sh Debug

BUILD_TYPE="${1:-Debug}"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

echo "[AIC-Starlink] Running tests"
echo "  Build type: ${BUILD_TYPE}"

if [[ ! -d "${BUILD_DIR}" ]]; then
  echo "[ERROR] Build directory not found. Run ./scripts/build.sh first."
  exit 1
fi

cd "${BUILD_DIR}"

echo "[AIC-Starlink] Ensuring build is up-to-date..."
cmake .. -DCMAKE_BUILD_TYPE="${BUILD_TYPE}"
cmake --build . -j

echo "[AIC-Starlink] Executing tests with CTest..."
ctest --output-on-failure --verbose

echo "[AIC-Starlink] All tests passed."