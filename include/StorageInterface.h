#pragma once

#include <vector>

class account;
class StorageInterface
{
public:
    virtual ~StorageInterface() = default;
    virtual void writeAccount(const account &acc) = 0;
    virtual std::vector <account> readAllAccounts() = 0;
private:
};