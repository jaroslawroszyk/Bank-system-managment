#pragma once

#include <vector>


class Account;


class StorageInterface
{
public:
    virtual ~StorageInterface() = default;

    virtual void writeAccount(const Account &) = 0;

    virtual std::vector<Account> readAllAccounts() = 0;

    virtual Account FindAccount(int) const = 0;

private:
    virtual void writeAllAccount() = 0;
};