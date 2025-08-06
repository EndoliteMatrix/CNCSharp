#ifndef CNCSHARP_MARLIN_COMMANDS_HPP
#define CNCSHARP_MARLIN_COMMANDS_HPP

#include <string>
#include <optional>
#include <unordered_map>

namespace cncsharp {

/// Enumeration of Marlin G-code and M-code commands supported by CNCSharp.
enum class GCodeCommand {
    // Linear motion
    G0,
    G1,
    // Arc motion
    G2,
    G3,
    // Dwell
    G4,
    // Homing
    G28,
    // Bed leveling
    G29,
    // Units
    G20,
    G21,
    // Positioning
    G90,
    G91,
    G92,
    // Temperature commands
    M104,
    M105,
    M109,
    M140,
    M190,
    // Motor and fan control
    M17,
    M18,
    M84,
    M106,
    M107,
    M80,
    M81,
    // SD card operations
    M20,
    M23,
    M24,
    M25,
    M26,
    M27,
    M28,
    M29,
    M30,
    M31,
    M32,
    M33,
    // Unknown / unsupported command
    Unknown
};

/// Representation of a parsed instruction. For now it holds only the command and the raw text.
struct GCodeInstruction {
    GCodeCommand command;
    std::string raw_line;
};

/// Convert an enumeration value to its canonical string (e.g., GCodeCommand::G0 -> "G0").
std::string to_string(GCodeCommand command);

/// Parse a command token (e.g., "G1") into a GCodeCommand enumeration.
GCodeCommand parse_command(const std::string& token);

} // namespace cncsharp

#endif // CNCSHARP_MARLIN_COMMANDS_HPP
