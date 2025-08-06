#ifndef CNCSHARP_IR_HPP
#define CNCSHARP_IR_HPP

#include <string>
#include <variant>
#include <vector>
#include <iostream>
#include <type_traits>

namespace cncsharp {

    /// A move operation for controlling machine axes. Values are in user-defined units.
    struct MoveOperation {
        double x{0.0};
        double y{0.0};
        double z{0.0};
        double feed_rate{0.0};
    };

    /// Set temperature operation (e.g. for 3D printer extruder or heated bed).
    struct SetTemperatureOperation {
        double temperature{0.0};
    };

    /// Comment operation to annotate programs. Comments are emitted in the target dialect as appropriate.
    struct CommentOperation {
        std::string text;
    };

    /// Variant type describing any supported operation. As the language grows, add new types here.
    using Operation = std::variant<MoveOperation, SetTemperatureOperation, CommentOperation>;

    /// Program holds a sequence of operations parsed from CNCSharp source.
    struct Program {
        std::vector<Operation> operations;
    };

    /// Dumps the program to the provided output stream in a human-readable form. Useful for debugging
    /// and logging. Consumers can override the stream to capture output elsewhere.
    inline void dump_program(const Program& program, std::ostream& os = std::cout) {
        for (const auto& op : program.operations) {
            std::visit([&os](auto&& arg) {
                using T = std::decay_t<decltype(arg)>;
                if constexpr (std::is_same_v<T, MoveOperation>) {
                    os << "MoveOperation: X=" << arg.x << " Y=" << arg.y << " Z=" << arg.z
                       << " F=" << arg.feed_rate << '\n';
                } else if constexpr (std::is_same_v<T, SetTemperatureOperation>) {
                    os << "SetTemperatureOperation: T=" << arg.temperature << '\n';
                } else if constexpr (std::is_same_v<T, CommentOperation>) {
                    os << "Comment: " << arg.text << '\n';
                }
            }, op);
        }
    }

} // namespace cncsharp

#endif // CNCSHARP_IR_HPP
