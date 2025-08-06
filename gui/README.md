# CNCSharp GUI

This folder will contain the source code for the graphical user interface (GUI) of the CNCSharp project. The GUI will provide a simple, modern interface for users to edit CNCSharp programs, compile them to target-specific output, preview machine paths, and manage settings.

## Goals

- Offer a clean and minimal code editor with syntax highlighting for the CNCSharp DSL.
- Support compiling CNCSharp files into target G-code or other machine dialects.
- Provide previews of tool paths and layer visualization.
- Expose configuration options for machine profiles, tool libraries, and material settings.
- Remain decoupled from the core compiler and back ends; the GUI will communicate with the compiler via an API or CLI invocation.

We will flesh out the GUI architecture and design as development progresses. For now, this placeholder clarifies where GUI-related code will reside.
