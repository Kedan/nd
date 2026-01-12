# Nudny Project Structure

This is project basic structure.

WORK IN PROGRESS

## Features
- cmake presets
- gtest
- asan
- ubsan
- valgrind
- helgrind
- coverage (line, branch)

## Requirements
- as above

## Build
./scripts directory contains .sh files, used to build code, generate coverage raports and clean workspace.

To build, use:
- ./scripts/build.sh <preset_name>

To clean, use:
- ./scripts/clean.sh <preset_name>

To clean, and remove build folder, use:
- ./scripts/clean.sh <preset_name> -x

To clean all: TO DO

Available <preset_name>:
- release
- debug
- asan
- valgrind
- helgrind
- coverage

## Run
- ./build/release/nd
- ./build/<preset_name>/nd

## Tests
Depends on what preset you build, choose one:
- ./scripts/build.sh debug

## Debugging
Address sanitizer:
- ./scripts/build.sh asan

Memory leak check:
- ./scripts/build.sh valgrind

Race conditioning test:
- ./scripts/build.sh helgrind

Coverage (line + branch):
- ./scripts/build.sh coverage

Coverage raports are generated in cov/ directory

## Project structure
- ./include - main header files
- ./src - main source files
- ./scripts - Bash scripts used for build/debug
- ./tests - Unit tests
- ./build - builded binaries
- ./cov - Generated coverage raports
- ./<My_module_dir> - Any module created (example: /foo, /bar). Structure should be as root directory structure
 
