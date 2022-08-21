#pragma once

#include "LoginInfo.h"
#include <fstream>

class Login
{
public:

    auto regstr() -> bool;

    auto Islogin() -> bool;

    auto menuLogin() -> void;

    auto setLogin() -> std::string;

    auto setPassword() -> std::string;

    const std::string getLog() const
    {
        return m_login;
    }

    const std::string getPas() const
    {
        return m_password;
    }

private:
    std::string m_login;
    std::string m_password;
};
