#pragma once

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "Bank.h"
#include "CliInput.h"

class Account : public Bank
{
public:
    Account(const InputInterface *input) : input(input)
    {}

    void create_acc();

    void showacc() const;

    void modify();

    void deposit(int deposit);

    void withdraw(int deposit);

    void raport() const;

    int returnacnumber() const;

    int returndeposit() const;

    char returntype() const;

    int getMAccnumber() const;

    const std::string &getMName() const;

    const std::string &getMSurname() const;

    int getMDeposit() const;

    char getMType() const;

    void setMAccnumber(int mAccnumber);

    void setMName(const std::string &mName);

    void setMSurname(const std::string &mSurname);

    void setMDeposit(int mDeposit);

    void setMType(char mType);

private:
    const InputInterface *input;
    int m_accnumber = -1;
    std::string m_name;
    std::string m_surname;
    int m_deposit = 0;
    char m_type = 'S';
};
