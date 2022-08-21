#include "../include/FileStorage.h"
#include "../include/Account.h"

void FileStorage::writeAccount(const Account &acc)
{
    std::ofstream writeAcc(FileName,std::ios::app);
//    writeAcc.open(FileName , std::ios::app);
    writeAcc << "#Surname: " << acc.getMSurname();
    writeAcc << "#Name: " << acc.getMName();
    writeAcc << "#Acc Number: " << acc.getMAccnumber();
    writeAcc << "#Deposit: " << acc.getMDeposit();
    writeAcc << "#Type: " << acc.getMType() << "\n";
    writeAcc.close();
}

std::vector<Account> FileStorage::readAllAccounts()
{
    std::vector<Account> accountss;
    std::ifstream inputFile(FileName,std::ios::app);
//    inputFile.open(FileName , std::ios::app);
    for (std::string line; getline(inputFile , line);)
    {
        size_t lastPos = 0;
        Account ac(nullptr);

        std::string surname;
        getStringData(line , lastPos , surname);
        ac.setMSurname(surname);

        std::string name;
        getStringData(line , lastPos , name);
        ac.setMName(name);

        int acoNumber;
        getIntData(line , lastPos , acoNumber);
        ac.setMAccnumber(acoNumber);

        int deposit;
        getIntData(line , lastPos , deposit);
        ac.setMDeposit(deposit);

        lastPos = line.find(':' , lastPos + 1);
        ac.setMType(line[lastPos + 2]);

        accountss.push_back(ac);
    }
    return accountss;
}

void FileStorage::getStringData(const std::string &line , size_t &lastPos , std::string &data)
{
    lastPos = line.find(':' , lastPos + 1);
    data = (line.substr(lastPos + 1 , line.find('#' , lastPos) - 1 - lastPos));
}

void FileStorage::getIntData(const std::string &line , size_t &lastPos , int &data)
{
    lastPos = line.find(':' , lastPos + 1);
    data = std::stoi(line.substr(lastPos + 1 , line.find('#' , lastPos) - 1 - lastPos));
}

void FileStorage::writeAllAccount()
{
    std::remove(FileName);
    for (const auto &account: accounts)
    {
        writeAccount(account);
    }
}

Account FileStorage::FindAccount(int accountNumber) const
{
    for (const auto &account: accounts)
    {
        if (accountNumber == account.getMAccnumber())
        {
            return account;
        }
    }
    Account ac(nullptr);
    return ac;
}

bool FileStorage::modifyAccount(Account &ac)
{
    for (auto &find: accounts)
    {
        if (find.getMAccnumber() == ac.getMAccnumber())
        {
            find.setMName(ac.getMName());
            find.setMSurname(ac.getMSurname());
            find.setMDeposit(ac.getMDeposit());
            find.setMType(ac.getMType());
            writeAllAccount();
            return true;
        }
    }
    return false;
}

bool FileStorage::deleteAccount(int accNumber)
{
    auto removeAccNumber = std::remove_if(accounts.begin() , accounts.end() , [accNumber](const Account &acc)
    {
        return accNumber == acc.getMAccnumber();
    });
    accounts.erase(removeAccNumber , accounts.end());
    writeAllAccount();
    return true;
}