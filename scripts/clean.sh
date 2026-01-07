#!/usr/bin/env bash

set -euo pipefail

PRESET="$1"
LINER="=========="

if [[ "$PRESET" == "all" ]]; then
	echo "$LINER Clean All $LINER"
else
	echo "$LINER Clean $PRESET $LINER"
	cmake --build --preset "clean-$PRESET"
	
	if [[ "$2" == "-x" ]]; then
		echo "($LINER) Remove ($PRESET) files and directories ($LINER)"
		echo "Remove build directory..."
		rm -rf ./build/"$PRESET"
		if [[ "$PRESET" == "coverage" ]]; then
			echo "Remove coverage raport dir..."
			rm -rf ./cov
			echo "Remove .info files"
			rm *.info
			echo "Remove .cleaned files"
			rm *.cleaned
		fi
	fi
fi
