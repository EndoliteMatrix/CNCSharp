#pragma once
#include <string>
#include <optional>
#include "cncsharp/communication.hpp"
#include "cncsharp/ir.hpp"

namespace cncsharp {

class SiemensInterface : public Communication {
public:
    SiemensInterface(const std::string& address, unsigned short port);
    virtual ~SiemensInterface();

    bool connect() override;
    void disconnect() override;
    bool is_connected() const override;
    bool send_line(const std::string& line) override;
    std::optional<std::string> read_line() override;
    ConnectionState state() const override { return m_state; }

    // Send an IR program to a Siemens controller
    bool send_program(const Program& program);

private:
    std::string m_address;
    unsigned short m_port;
    ConnectionState m_state;
};

} // namespace cncsharp
