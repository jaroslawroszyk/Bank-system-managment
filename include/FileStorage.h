#pragma once

#include "StorageInterface.h"
#include <fstream>
#include "CliInput.h"

#define FileName "data.txt"
class account;

class FileStorage : public StorageInterface
{
public:
    FileStorage()
    {
        accounts = readAllAccounts();
    }

    void writeAccount(const account &acc) override;

    std::vector<account> readAllAccounts() override;
    account FindAccount(int accountNumber) const;

    ~FileStorage()
    {
        writeAllAccount();
    }
private:
    std::vector<account> accounts;
//    static constexpr char* FileName =  "data.txt";
    void writeAllAccount();

    static void getStringData(const std::string &line, size_t &lastPos, std::string &data) ;
    static void getIntData(const std::string &line, size_t &lastPos, int &data) ;
};
