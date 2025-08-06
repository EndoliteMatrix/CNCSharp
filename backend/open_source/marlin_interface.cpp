#include "open_source/marlin_interface.hpp"
#include "cncsharp/logger.hpp"

namespace cncsharp {

MarlinInterface::MarlinInterface(const std::string& port, int baud)
    : m_port(port), m_baud(baud), m_state(ConnectionState::Disconnected) {}

MarlinInterface::~MarlinInterface() {
    if (is_connected()) {
        disconnect();
    }
}

bool MarlinInterface::connect() {
    CN_LOG_INFO("MarlinInterface::connect called");
    // TODO: Open serial connection to the Marlin controller
    m_state = ConnectionState::Connected;
    return true;
}

void MarlinInterface::disconnect() {
    CN_LOG_INFO("MarlinInterface::disconnect called");
    // TODO: Close serial connection
    m_state = ConnectionState::Disconnected;
}

bool MarlinInterface::is_connected() const {
    return m_state == ConnectionState::Connected;
}

ConnectionState MarlinInterface::state() const {
    return m_state;
}

bool MarlinInterface::send_line(const std::string& line) {
    CN_LOG_DEBUG("Sending to Marlin: {}", line);
    // TODO: Write line to serial port
    return true;
}

std::optional<std::string> MarlinInterface::read_line() {
    // TODO: Read line from serial port and return it
    return std::nullopt;
}

bool MarlinInterface::send_program(const Program& program) {
    CN_LOG_INFO("Sending program to Marlin with {} operations", program.operations.size());
    for (const auto& op : program.operations) {
        // TODO: Translate operation into Marlin G-code and send
        send_line("; TODO: translate operation");
    }
    return true;
}

} // namespace cncsharp
