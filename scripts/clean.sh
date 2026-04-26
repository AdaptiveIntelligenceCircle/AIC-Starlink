#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "[AIC-Starlink] Cleaning repository build artifacts..."

rm -rf "${ROOT_DIR}/build"
rm -rf "${ROOT_DIR}/reports"

echo "[AIC-Starlink] Clean finished."