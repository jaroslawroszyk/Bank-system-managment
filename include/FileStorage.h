#pragma once

#include "StorageInterface.h"
#include <fstream>
#include "CliInput.h"
#include <string>
#include <algorithm>

#define FileName "data.txt"


class Account;

class FileStorage : public StorageInterface
{
public:
    FileStorage()
    {
        accounts = readAllAccounts();
    }

    void writeAccount(const Account &acc) override;


    std::vector<Account> readAllAccounts() override;

    Account FindAccount(int accountNumber) const override;

    bool modifyAccount(Account &ac);

    bool deleteAccount(int accNumber);

    ~FileStorage()
    {
    }
private:

    std::vector<Account> accounts;
    static void getStringData(const std::string &line , size_t &lastPos , std::string &data);

    void writeAllAccount() override;

    static void getIntData(const std::string &line , size_t &lastPos , int &data);
};
