#pragma once
#include "bank.h"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

class Functionality
{

public:
    void writeAccount();

    void displayDetails(int numberAccount);

    void modifyAccount(int numberAccount);

    void deleteAccount(int numberAccount);

    void displayAllAccount();

    void depositOrWithdraw(int numberAccount, int option);

    void enterAccNo();

    void cleaningScreen();
};