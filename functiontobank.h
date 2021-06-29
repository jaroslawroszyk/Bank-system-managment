#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <algorithm>

void writeAccount();
void displayDetails(int numberAccount);
void modifyAccount(int numberAccount);
void deleteAccount(int numberAccount);
void displayAllAccount();
void depositOrWithdraw(int numberAccount, int option);
void enterAccNo();
void cleaningScreen();
