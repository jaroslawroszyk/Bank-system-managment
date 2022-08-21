#pragma once

#include <vector>

class Account;
class StorageInterface
{
public:
    virtual ~StorageInterface() = default;
    virtual void writeAccount(const Account &acc) = 0;
    virtual std::vector <Account> readAllAccounts() = 0;
private:
};