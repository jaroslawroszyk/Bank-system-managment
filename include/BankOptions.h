#pragma once

#include <iostream>

namespace Operation
{
    enum class BankOptions
    {
        s_newaccount = 1 ,
        s_deposit ,
        s_withdraw ,
        s_balance ,
        s_holder ,
        s_closeacc ,
        s_modify ,
        s_exit = 8 ,
    };
} // namespace Operation
std::istream &operator>>(std::istream &in , Operation::BankOptions &enter);
//Operation::BankOptions
void menu();