#include "cncsharp/ir.hpp"
#include <string>
#include <sstream>
#include "cncsharp/logger.hpp"
#include <type_traits>

namespace cncsharp {

/// Generates a generic G-code representation from the provided program.
///
/// This function iterates through the operations in a `Program` and emits a
/// simplistic, generic G-code string. The generated code is intentionally
/// naive and meant only as demonstration; real back-ends should tailor
/// output to the capabilities and dialect of the target machine (e.g., Marlin,
/// GRBL, Fanuc). Comments are emitted with a leading semicolon, while
/// unsupported operations may be ignored or cause an error in future revisions.
std::string generate_gcode(const Program& program) {
    std::ostringstream out;
            // Initialize logging to INFO level
                Logger::instance().set_level(LogLevel::Info);
                CN_LOG_INFO("Starting G-code generation");
    for (const auto& op : program.operations) {
        std::visit([&out](auto&& arg) {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, MoveOperation>) {
                // Emit a linear move (G1) with X, Y, Z coordinates and feed rate.
                            CN_LOG_INFO("Processing MoveOperation");
                out << "G1";
                out << " X" << arg.x;
                out << " Y" << arg.y;
                out << " Z" << arg.z;
                out << " F" << arg.feed_rate;
                out << '\n';
            } else if constexpr (std::is_same_v<T, SetTemperatureOperation>) {
                            CN_LOG_INFO("Processing SetTemperatureOperation");
                // Emit a comment for setting temperature; actual command depends on firmware.
                            CN_LOG_INFO("Processing CommentOperation");
                out << "; Set temperature to " << arg.temperature << '\n';
            } else if constexpr (std::is_same_v<T, CommentOperation>) {
                // Emit the comment line with semicolon.
                out << ';' << arg.text << '\n';
            } else {
                            CN_LOG_WARN("Unsupported operation encountered");
                // Unhandled operation type; ignore or handle error.
            }
        }, op);
    }
    return out.str();
}

} // namespace cncsharp
