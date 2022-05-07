#pragma once
#include <iostream>
#include <string>

class InputInterface
{
public:
    virtual ~InputInterface() = default;

    virtual int getAccountNumber() const = 0;
    virtual std::string getSurname() const = 0;
    virtual std::string getName() const = 0;
    virtual char getAccountType() const = 0;
    virtual int getDepositAmount() const = 0;
private:
};