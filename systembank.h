#ifndef SYSTEMBANK_H_
#define SYSTEMBANK_H_
#include <iostream>
enum class SystemBank
{
    nope = 0,
    s_newaccount = 1,
    s_deposit,
    s_withdraw,
    s_balance,
    s_holder,
    s_closeacc,
    s_modify,
    s_exit
};

std::istream &operator>>(std::istream &in, SystemBank &entry);
// std::istream &operator>>(std::istream &in, SystemBank &menu);
void menu();

#endif