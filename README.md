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
In project directory:

- cmake --preset <preset_name> 
- cmake --build --preset <preset_name>

Clean: 
- cmake --build --preset clean-<preset_name>

Debug build:
- cmake --preset debug
- cmake --build --preset debug

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
- ctest --preset <preset_name>

## Debugging
Unit Tests:
- cmake --preset debug
- cmake --build --preset debug
- ctest --preset debug

Address sanitizer:
- cmake --preset asan
- cmake --build --preset asan
- ctest -V --preset asan

Memory leak check:
- cmake --preset valgrind
- cmake --build --preset valgrind 
- ctest -V --preset valgrind
- valgrind ./build/valgrind/nudny

Race conditioning test:
- cmake --preset helgrind
- cmake --build --preset helgrind
- ctest -V --preset helgrind
- valgrind --tool=helgrind ./build/helgrind/nudny

Coverage (line + branch):
- cmake --preset coverage
- cmake --build --preset coverage
- cmake --build --preset coverage --target coverage

Coverage raports are generated in cov/ directory

## Project structure
- ./include - main header files
- ./src - main source files
- ./scripts - Bash scripts used for build/debug
- ./tests - Unit tests
- ./build - builded binaries
- ./cov - Generated coverage raports
- ./<My_module_dir> - Any module created (example: /foo, /bar). Structure should be as root directory structure
 
