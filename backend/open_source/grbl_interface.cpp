#include "open_source/grbl_interface.hpp"
#include "cncsharp/logger.hpp"

namespace cncsharp {

GrblInterface::GrblInterface(const std::string& port, int baud)
    : m_port(port), m_baud(baud), m_state(ConnectionState::Disconnected) {}

GrblInterface::~GrblInterface() {
    if (is_connected()) {
        disconnect();
    }
}

bool GrblInterface::connect() {
    CN_LOG_INFO("GrblInterface::connect called");
    m_state = ConnectionState::Connected;
    return true;
}

void GrblInterface::disconnect() {
    CN_LOG_INFO("GrblInterface::disconnect called");
    m_state = ConnectionState::Disconnected;
}

bool GrblInterface::is_connected() const {
    return m_state == ConnectionState::Connected;
}

ConnectionState GrblInterface::state() const {
    return m_state;
}

bool GrblInterface::send_line(const std::string& line) {
    CN_LOG_DEBUG("Sending to GRBL: {}", line);
    return true;
}

std::optional<std::string> GrblInterface::read_line() {
    return std::nullopt;
}

bool GrblInterface::send_program(const Program& program) {
    CN_LOG_INFO("Sending program to GRBL with {} operations", program.operations.size());
    for (const auto& op : program.operations) {
        send_line("; TODO: translate operation for GRBL");
    }
    return true;
}

} // namespace cncsharp
