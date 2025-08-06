# Open-source Machine Support

This directory contains interfaces and implementations for communicating with open-source CNC and 3D printer firmware such as Marlin, GRBL, Klipper, and others. Each submodule implements the `Communication` interface defined in `include/cncsharp/communication.hpp`.

## Structure

- `marlin_interface.hpp` – Provides a C++ interface for sending CNCSharp IR to Marlin-based controllers. This implementation translates operations into Marlin G‑code commands and manages serial communication.
- `grbl_interface.hpp` – (Planned) Interface for GRBL firmware.
- Additional firmware (Klipper, Smoothieware, etc.) can be added here following the same pattern.
