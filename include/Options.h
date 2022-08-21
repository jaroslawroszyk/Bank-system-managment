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

} // namespace Options
std::istream &operator>>(std::istream &in , Options::Login &entry);
