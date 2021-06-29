#pragma once
#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include <algorithm>


class account
{
private:
    int m_accnumber;
    char m_name[50];
    char m_surname[50];
    int m_deposit;
    char m_type;

public:
    void create_acc();
    void showacc() const;
    void modify();
    void deposit(int deposit);
    void withdraw(int deposit);
    void report() const; 
    int returnacnumber() const;
    int returndeposit() const;
    char returntype() const;
};
