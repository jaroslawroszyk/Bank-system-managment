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

    void displayDetails(int numberAccount);

    void modifyAccount(int numberAccount);

    void deleteAccount(int numberAccount);

    void displayAllAccount();

    void depositOrWithdraw(int numberAccount, int option);

    static void enterAccNo();

//    void cleaningScreen();

    void generateRaport() const;

    int optionDeposit(int option, Account &aco, int amount) const;

    int optionWithdraw(int option, Account &aco, int amount) const;
};