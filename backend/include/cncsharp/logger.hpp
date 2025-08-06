#pragma once

#include <iostream>
#include <string>

namespace cncsharp {

/**
 * @brief Logging levels for CNCSharp backend.
 *
 * Levels are ordered such that lower numerical values correspond to more
 * critical messages. The Logger will emit a message only if its level is
 * less than or equal to the current global logging level.
 */
enum class LogLevel {
    Error = 0,
    Warn  = 1,
    Info  = 2,
    Debug = 3
};

/**
 * @brief Simple singleton logger for the CNCSharp backend.
 *
 * This logger writes messages to std::clog. It exposes a static
 * interface for setting the current log level and emitting messages.
 * In the future, this could be extended to support sinks, formatting,
 * timestamps, thread identifiers, or integration with external logging
 * libraries. For now, it provides a straightforward mechanism for
 * verbose diagnostics in development builds.
 */
class Logger {
public:
    /// Set the global log level. Messages with a level higher than this
    /// will be suppressed.
    static void set_level(LogLevel level) { current_level() = level; }

    /// Retrieve the current global log level.
    static LogLevel level() { return current_level(); }

    /// Log a message at the given log level. Accepts a variadic pack of
    /// arguments that will be forwarded to std::clog using a fold
    /// expression. A newline is appended automatically.
    template <typename... Args>
    static void log(LogLevel level, Args&&... args) {
        if (level <= current_level()) {
            ((std::clog << std::forward<Args>(args)), ...);
            std::clog << std::endl;
        }
    }

private:
    /// Storage for the current log level. Initialized to Info by default.
    static LogLevel& current_level() {
        static LogLevel lvl = LogLevel::Info;
        return lvl;
    }
};

// Convenience macros for logging at specific levels. These macros avoid
// evaluating their arguments when the message would be suppressed.
#define CN_LOG(level, ...) ::cncsharp::Logger::log(level, __VA_ARGS__)
#define CN_LOG_ERROR(...) CN_LOG(::cncsharp::LogLevel::Error, __VA_ARGS__)
#define CN_LOG_WARN(...)  CN_LOG(::cncsharp::LogLevel::Warn,  __VA_ARGS__)
#define CN_LOG_INFO(...)  CN_LOG(::cncsharp::LogLevel::Info,  __VA_ARGS__)
#define CN_LOG_DEBUG(...) CN_LOG(::cncsharp::LogLevel::Debug, __VA_ARGS__)

} // namespace cncsharp
