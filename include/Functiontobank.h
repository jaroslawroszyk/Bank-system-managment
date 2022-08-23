#pragma once

#include "Account.h"
#include "OutputInterface.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

class FunctionalityForAccount : public OutputInterface
{
public:
    static void writeAccount();

    auto displayDetails(int numberAccount)->void;

    auto modifyAccount(int numberAccount)->void;

    auto deleteAccount(int numberAccount)->void;

    auto displayAllAccount()->void override;

    auto depositOrWithdraw(int numberAccount , int option)->void;

    static void enterAccNo();

    auto generateRaport() const->void override;

    auto optionDeposit(int option , Account &aco , int amount) const->int;

    auto optionWithdraw(int option , Account &aco , int amount) const->int;
};