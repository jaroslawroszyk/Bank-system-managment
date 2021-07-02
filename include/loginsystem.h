#pragma once
#include <iostream>
#include <fstream>

enum class LoginSystem
{
    wrong = 0,
    regi = 1,
    logi,
};

std::istream &operator>>(std::istream &in, LoginSystem &entry);

bool rgstr();
bool login();
void menuLogin();
