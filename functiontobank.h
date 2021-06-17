#ifndef FUNCTIONTOBANK_H_
#define FUNCTIONTOBANK_H_
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <algorithm>

void writeAccount();
void displayDetails(int n);
void modifyAccount(int n);
void deleteAccount(int n);
void displayAllAccount();
void depositOrWithdraw(int n, int op);
void enterAccNo();
void cleaningScreen();

#endif