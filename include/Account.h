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
    explicit Account(const InputInterface *input) : input(input)
    {}

    void create_acc() override;

    void showacc() const override;

    void modify() override;

    void deposit(int deposit);

    void withdraw(int deposit);

    void raport() const;

    [[nodiscard]] int returnacnumber() const;

    [[nodiscard]] int returndeposit() const;

    [[nodiscard]] char returntype() const;

    [[nodiscard]] int getMAccnumber() const;

    [[nodiscard]] const std::string &getMName() const;

    [[nodiscard]] const std::string &getMSurname() const;

    [[nodiscard]] int getMDeposit() const;

    [[nodiscard]] char getMType() const;

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
