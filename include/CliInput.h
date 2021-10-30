#pragma once

#include <algorithm>
#include "inputInterface.h"

class CliInput : public InputInterface
{
public:
    int getAccountNumber() const override;

    std::string getSurname() const override;

    std::string getName() const override;

    char getAccountType() const override;

    int getDepositAmount() const override;
    ~CliInput() = default;

private:
    bool isNumber(const std::string &s) const
    {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }
};