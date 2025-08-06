# Protected (Vendor) Machine Support

This directory contains proprietary interfaces and implementations for communicating with closed-source CNC controllers and industrial machinery from vendors such as Siemens, Fanuc, Haas, and others. These controllers often require special protocols or SDKs. Each interface will inherit from the generic `Communication` class and translate CNCSharp IR operations into vendor-specific commands.

## Structure

- `siemens_interface.hpp` – Provides a skeleton for interfacing with Siemens CNC controllers. Implementation details depend on Siemens communication libraries.
- Additional vendor interfaces (Fanuc, Haas, Mazak, etc.) can be added here following the same pattern.
