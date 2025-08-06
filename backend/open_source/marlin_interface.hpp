#pragma once
#include <string>
#include <optional>
#include "cncsharp/communication.hpp"
#include "cncsharp/ir.hpp"

namespace cncsharp {

class MarlinInterface : public Communication {
public:
    MarlinInterface(const std::string& port, unsigned long baud);
    virtual ~MarlinInterface();

    bool connect() override;
    void disconnect() override;
    bool is_connected() const override;
    bool send_line(const std::string& line) override;
    std::optional<std::string> read_line() override;
    ConnectionState state() const override { return m_state; }

    // Translate and send an IR program to a Marlin controller.
    bool send_program(const Program& program);

private:
    std::string m_port;
    unsigned long m_baud;
    ConnectionState m_state;
};

} // namespace cncsharp
