#!usr/bin/env bash .. 
set -euo pipefail 

# AIC-Starlink Build Script.. 
# Usage; 
# ./scripts/build.sh 
#
#Examples: 
#./scripts/build.sh Debug..
#./scripts/build.sh Release Clean

BUILD_TYPE="${1:-Debug}"
CLEAN="${2:-}"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

echo "[AIC-Starlink] Build started"
echo "  Root: ${ROOT_DIR}"
echo "  Build type: ${BUILD_TYPE}"
echo "  Build dir: ${BUILD_DIR}"

if [[ "${CLEAN}" == "clean" ]]; then
  echo "[AIC-Starlink] Cleaning build directory..."
  rm -rf "${BUILD_DIR}"
fi

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

echo "[AIC-Starlink] Configuring with CMake..."
cmake .. -DCMAKE_BUILD_TYPE="${BUILD_TYPE}"

echo "[AIC-Starlink] Building..."
cmake --build . -j

echo "[AIC-Starlink] Build finished successfully."