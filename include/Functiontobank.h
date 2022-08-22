#pragma once
#include "Account.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

class FunctionalityForAccount
{
//extract some method to new class ?
public:
    static void writeAccount();

    auto displayDetails(int numberAccount)->void;

    auto modifyAccount(int numberAccount)-> void;

    auto deleteAccount(int numberAccount) -> void;

    auto displayAllAccount() -> void;

    auto depositOrWithdraw(int numberAccount, int option) -> void;

    static void enterAccNo();

//    void cleaningScreen();

    auto generateRaport() const -> void;

    auto optionDeposit(int option, Account &aco, int amount) const -> int;

    auto optionWithdraw(int option, Account &aco, int amount) const -> int;
};