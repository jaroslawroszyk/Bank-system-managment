#ifndef LOGINSYSTEM_H_
#define LOGINSYSTEM_H_
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

#endif