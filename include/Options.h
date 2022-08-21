#pragma once

#include <iostream>

namespace Options
{
    enum class Login
    {
        wrong = 0 ,
        registrtation = 1 ,
        login ,
    };

    void cleaningScreen()
    {
        std::cout << "\033[2J\033[1;1H";
    }

} // namespace Options
std::istream &operator>>(std::istream &in , Options::Login &entry);
