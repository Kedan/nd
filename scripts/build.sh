#!/usr/bin/env bash

set -euo pipefail

echo "Build...."

PRESET="$1"
LINER="=========="

if [[ "$PRESET" == "all" ]]; then
	echo "TODO"
else

	echo "($LINER) Configure ($PRESET) ($LINER)"
	cmake --preset "$PRESET"
	
	echo "($LINER)  Build ($PRESET) ($LINER)"
	cmake --build --preset "$PRESET"
	
	echo "($LINER)  Unit Tests on ($PRESET) ($LINER)"
	ctest --preset "$PRESET" -V
	
	if [[ "$PRESET" == "asan" ]]; then
		echo "($LINER) Sanitizers ($LINER)"
		valgrind --error-exitcode=1 ctest --preset "$PRESET"
	fi
	
	if [[ "$PRESET" == "valgrind" ]]; then
		echo "($LINER) Valgrind Memcheck ($LINER)"
		valgrind ../build/valgrind/nd
	fi
	
	if [[ "$PRESET" == "helgrind" ]]; then
		echo "($LINER) Helgrind ($LINER)"
		valgrind --tool=helgrind ../build/valgrind/nd
	fi
	
	if [[ "$PRESET" == "coverage" ]]; then
		echo "($LINER) Coverage ($LINER)"
		cmake --build --preset coverage --target coverage
	fi

fi

echo "Done."
