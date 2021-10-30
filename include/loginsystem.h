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

    bool login();

    void menuLogin();
};
