#pragma once
#include <iostream>

enum class SystemBank
{
    s_newaccount=1,
    s_deposit,
    s_withdraw,
    s_balance,
    s_holder,
    s_closeacc,
    s_modify,
    s_exit = 8,
    // nope
};

std::istream &operator>>(std::istream &in, SystemBank &enter);
// std::istream &operator>>(std::istream &in, SystemBank &menu);
void menu();
