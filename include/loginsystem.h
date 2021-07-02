#pragma once
#include <fstream>
#include <iostream>

enum class LoginSystem
{
    wrong = 0,
    regi = 1,
    logi,
};

std::istream &operator>>(std::istream &in, LoginSystem &entry);

bool regstr();
bool login();
void menuLogin();
