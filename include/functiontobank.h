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

    bool ifFileIsReading(int numberAccount, account &aco, std::ifstream &inFile) const;

    bool isModify(int numberAccount, account &aco, std::fstream &File) const;

    void IfDataIsNotCorrect(int numberAccount, account &aco, std::ifstream &inFile, std::ofstream &outFile) const;

    void generateRaport(account &aco, std::ifstream &inFile) const;

    int optionDeposit(int option, account &aco, int amount) const;

    int optionWithdraw(int option, account &aco, int amount) const;
};