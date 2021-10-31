#pragma once
#include "account.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

class Functionality
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

    void cleaningScreen();


    void generateRaport() const;

    int optionDeposit(int option, account &aco, int amount) const;

    int optionWithdraw(int option, account &aco, int amount) const;
};