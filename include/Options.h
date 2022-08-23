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

    auto cleaningScreen() -> void
    {
        std::cout << "\033[2J\033[1;1H";
    }

} // namespace Options
std::istream &operator>>(std::istream &in , Options::Login &entry);
