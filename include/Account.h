#pragma once

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include "BankOperation.h"
#include "CliInput.h"
#include "Person.h"

class Account : public BankOperation , public Person
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

    [[nodiscard]] int getMDeposit() const;

    [[nodiscard]] char getMType() const;

    void setMAccnumber(int mAccnumber);

    void setMDeposit(int mDeposit);

    void setMType(char mType);

private:
    const InputInterface *input;
    int m_accnumber = -1;
    int m_deposit = 0;
    char m_type = 'S';
};
