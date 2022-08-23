#pragma once

#include <algorithm>
#include "InputInterface.h"

class ClInput : public InputInterface
{
public:
    auto getAccountNumber() const -> int override;

    auto getSurname() const -> std::string override;

    auto getName() const -> std::string override;

     auto getAccountType() const -> char override;

    auto getDepositAmount() const -> int override;
    ~ClInput() = default;

private:
    auto isNumber(const std::string &s) const -> bool
    {
        return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
    }
};