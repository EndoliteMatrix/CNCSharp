#pragma once

#include <string>
#include <optional>

namespace cncsharp {

// Represents the state of a communication link to a machine controller.
// Communication implementations should update the state as they connect,
// disconnect, or encounter errors during data transmission.
enum class ConnectionState {
    Disconnected,
    Connecting,
    Connected,
    Error
};

// Abstract base class for machine communication.
// Specific implementations (serial, network, USB, etc.) should derive from this
// class and implement the virtual methods to manage connections and data transfer.
class Communication {
public:
    virtual ~Communication() = default;

    // Attempt to establish a connection to the machine controller.
    // Returns true if the connection is successfully established.
    virtual bool connect() = 0;

    // Close the connection to the machine controller.
    virtual void disconnect() = 0;

    // Check if the communication link is currently connected.
    virtual bool is_connected() const = 0;

    // Send a single line of text (e.g., a G-code command) to the machine.
    // Returns true if the line was sent successfully.
    virtual bool send_line(const std::string &line) = 0;

    // Read a single line of response from the machine.
    // Returns an optional string containing the line, or std::nullopt if no line is available.
    virtual std::optional<std::string> read_line() = 0;

    // Retrieve the current connection state.
    virtual ConnectionState state() const = 0;
};

} // namespace cncsharp
