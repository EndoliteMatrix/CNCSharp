// Implementation of Marlin G-code command helper functions
// This file implements the functions declared in marlin_commands.hpp
// It provides mappings between enumeration values and string representations
// and a parser to convert string tokens into enumeration values.

#include "cncsharp/marlin_commands.hpp"
#include <algorithm>
#include <cctype>
#include <unordered_map>

namespace cncsharp {

// Convert GCodeCommand enum to human-readable string
std::string to_string(GCodeCommand command) {
    switch (command) {
    case GCodeCommand::G0: return "G0";
    case GCodeCommand::G1: return "G1";
    case GCodeCommand::G2: return "G2";
    case GCodeCommand::G3: return "G3";
    case GCodeCommand::G4: return "G4";
    case GCodeCommand::G28: return "G28";
    case GCodeCommand::G29: return "G29";
    case GCodeCommand::G20: return "G20";
    case GCodeCommand::G21: return "G21";
    case GCodeCommand::G90: return "G90";
    case GCodeCommand::G91: return "G91";
    case GCodeCommand::G92: return "G92";
    case GCodeCommand::M104: return "M104";
    case GCodeCommand::M105: return "M105";
    case GCodeCommand::M109: return "M109";
    case GCodeCommand::M140: return "M140";
    case GCodeCommand::M190: return "M190";
    case GCodeCommand::M17: return "M17";
    case GCodeCommand::M18: return "M18";
    case GCodeCommand::M84: return "M84";
    case GCodeCommand::M106: return "M106";
    case GCodeCommand::M107: return "M107";
    case GCodeCommand::M80: return "M80";
    case GCodeCommand::M81: return "M81";
    case GCodeCommand::M20: return "M20";
    case GCodeCommand::M23: return "M23";
    case GCodeCommand::M24: return "M24";
    case GCodeCommand::M25: return "M25";
    case GCodeCommand::M26: return "M26";
    case GCodeCommand::M27: return "M27";
    case GCodeCommand::M28: return "M28";
    case GCodeCommand::M29: return "M29";
    case GCodeCommand::M30: return "M30";
    case GCodeCommand::M31: return "M31";
    case GCodeCommand::M32: return "M32";
    case GCodeCommand::M33: return "M33";
    default:
        return "Unknown";
    }
}

// Helper function to normalize a token to uppercase for case-insensitive matching
static std::string normalize_token(const std::string &token) {
    std::string result;
    result.reserve(token.size());
    for (char c : token) {
        result.push_back(static_cast<char>(std::toupper(static_cast<unsigned char>(c))));
    }
    return result;
}

// Parse a token string into a GCodeCommand enumeration value
GCodeCommand parse_command(const std::string &token) {
    static const std::unordered_map<std::string, GCodeCommand> kLookup = {
        {"G0", GCodeCommand::G0}, {"G1", GCodeCommand::G1}, {"G2", GCodeCommand::G2}, {"G3", GCodeCommand::G3},
        {"G4", GCodeCommand::G4}, {"G28", GCodeCommand::G28}, {"G29", GCodeCommand::G29}, {"G20", GCodeCommand::G20},
        {"G21", GCodeCommand::G21}, {"G90", GCodeCommand::G90}, {"G91", GCodeCommand::G91}, {"G92", GCodeCommand::G92},
        {"M104", GCodeCommand::M104}, {"M105", GCodeCommand::M105}, {"M109", GCodeCommand::M109}, {"M140", GCodeCommand::M140},
        {"M190", GCodeCommand::M190}, {"M17", GCodeCommand::M17}, {"M18", GCodeCommand::M18}, {"M84", GCodeCommand::M84},
        {"M106", GCodeCommand::M106}, {"M107", GCodeCommand::M107}, {"M80", GCodeCommand::M80}, {"M81", GCodeCommand::M81},
        {"M20", GCodeCommand::M20}, {"M23", GCodeCommand::M23}, {"M24", GCodeCommand::M24}, {"M25", GCodeCommand::M25},
        {"M26", GCodeCommand::M26}, {"M27", GCodeCommand::M27}, {"M28", GCodeCommand::M28}, {"M29", GCodeCommand::M29},
        {"M30", GCodeCommand::M30}, {"M31", GCodeCommand::M31}, {"M32", GCodeCommand::M32}, {"M33", GCodeCommand::M33}
    };

    std::string norm = normalize_token(token);
    auto it = kLookup.find(norm);
    if (it != kLookup.end()) {
        return it->second;
    }
    return GCodeCommand::Unknown;
}

} // namespace cncsharp
