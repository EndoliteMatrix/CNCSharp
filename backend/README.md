# CNCSharp Backend

This directory contains the core implementation that turns CNCSharp intermediate representations (IR) into executable machine instructions and supports integration with various firmware targets.

## Contents

- **include/cncsharp/ir.hpp** — defines C++ data structures representing CNCSharp programs and operations. These structures mirror the IR defined in the parser.
- **include/cncsharp/logger.hpp** — simple logging utility and macros used throughout the backend.
- **src/generator.cpp** — stub implementation of a generator that translates the IR into generic G-code commands. This will be extended to handle more operations and target-specific dialects.
- **CMakeLists.txt** — build configuration for the backend library using CMake.

## Goals

The backend will:
1. Provide a stable C++ API that higher-level tools (CLI, GUI, or external programs) can use to compile and emit machine code.
2. Translate the high-level CNCSharp language into various machine dialects (Marlin G-code, GRBL, Siemens, etc.) by implementing generators for each target.
3. Include extensible logging and diagnostic output to aid debugging and introspection.
4. Remain loosely coupled to the frontend parser to allow independent evolution.

As development progresses, this README will be updated with build instructions and usage examples.
