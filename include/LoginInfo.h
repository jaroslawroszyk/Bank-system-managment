#pragma once

#include <iostream>

enum class loginInformation
{
    wrong = 0,
    registration = 1,
    login,
};

std::istream &operator>>(std::istream &in, loginInformation &);