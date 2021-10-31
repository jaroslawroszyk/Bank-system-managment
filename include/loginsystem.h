#pragma once

#include <fstream>
#include <iostream>
#include <cstdlib>

enum class LoginSystem
{
    wrong = 0,
    regi = 1,
    logi,
};

std::istream &operator>>(std::istream &in, LoginSystem &entry);

class Login
{
public:

    bool regstr();

    bool Islogin();

    void menuLogin();

    std::string getLogin();

    std::string getPassword();

    const std::string getLog() const
    {
        return m_login;
    }

    const std::string getPas() const
    {
        return m_password;
    }

    void setMLogin(const std::string &mLogin);

    void setMPassword(const std::string &mPassword);

private:

    std::string m_login;
    std::string m_password;
};
