#!/bin/bash

set -euo pipefail

DIR="$(pwd)"
echo "Nudny coverage raport generator"

LCOV_DIR="$DIR/cov/lcov-html"
BCOV_DIR="$DIR/cov/bcov-html"
LDIR="$DIR"
BDIR="$DIR"

LINE_COV_PREFIX="line-"
BRANCH_COV_PREFIX="branch-"

echo "Line coverage..."
lcov --capture \
	--ignore-errors inconsistent \
	--directory "$LDIR" \
	--output-file "$LDIR/${LINE_COV_PREFIX}coverage.info"
lcov --remove "$LDIR/${LINE_COV_PREFIX}coverage.info" '/usr/*' '*/_deps/*' --output-file "$LDIR/${LINE_COV_PREFIX}coverage.cleaned"
genhtml "$LDIR/${LINE_COV_PREFIX}coverage.cleaned" --output-directory "$LCOV_DIR"
echo "Ok."

echo "Branch coverage..."
lcov --capture \
	--ignore-errors inconsistent \
   	--rc branch_coverage=1 \
	--directory "$BDIR" \
	--output-file "$BDIR/${BRANCH_COV_PREFIX}coverage.info"
lcov --remove "$BDIR/${BRANCH_COV_PREFIX}coverage.info" '/usr/*' '*/_deps/*' --output-file "$BDIR/${BRANCH_COV_PREFIX}coverage.cleaned"
genhtml --branch-coverage "$BDIR/${BRANCH_COV_PREFIX}coverage.cleaned" --output-directory "$BCOV_DIR"
echo "Ok."
echo "Done."
