#pragma once
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>

void writeAccount();
void displayDetails(int numberAccount);
void modifyAccount(int numberAccount);
void deleteAccount(int numberAccount);
void displayAllAccount();
void depositOrWithdraw(int numberAccount, int option);
void enterAccNo();
void cleaningScreen();
