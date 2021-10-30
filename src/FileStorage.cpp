#include "FileStorage.h"
#include "account.h"

void FileStorage::writeAccount(const account &acc)
{
    std::ofstream writeAcc;
    writeAcc.open(FileName, std::ios::app);
    writeAcc << "#Surname: " << acc.getMSurname();
    writeAcc << "#Name: " << acc.getMName();
    writeAcc << "#Acc Number: " << acc.getMAccnumber();
    writeAcc << "#Deposit: " << acc.getMDeposit();
    writeAcc << "#Type: " << acc.getMType() << "\n";
    writeAcc.close();
}

std::vector<account> FileStorage::readAllAccounts()
{
    std::vector<account> accounts;
    std::ifstream inputFile;
    inputFile.open(FileName, std::ios::app);
    for (std::string line; getline(inputFile, line);)
    {
        size_t lastPos = 0;
        //#Surname: sada#Name: asd#Acc Number: 1#Deposit: 2131321#Type P
        //No    Surname     Name     Type   Balance
        //1     sada#Name: a         asd#Acc Number: 1#Depo          2131321
        account ac(nullptr);

        std::string surname;
        getStringData(line, lastPos, surname);
        ac.setMSurname(surname);

        std::string name;
        getStringData(line, lastPos, name);
        ac.setMName(name);

        int acoNumber;
        getIntData(line, lastPos, acoNumber);
        ac.setMAccnumber(acoNumber);

        int deposit;
        getIntData(line, lastPos, deposit);
        ac.setMDeposit(deposit);

        lastPos = line.find(":", lastPos + 1);
        ac.setMType(line[lastPos + 2]);

        accounts.push_back(ac);
    }
    return accounts;
}

void FileStorage::getStringData(const std::string &line, size_t &lastPos, std::string &data) const
{
    lastPos = line.find(":", lastPos + 1);
    data = (line.substr(lastPos + 1, line.find("#", lastPos) - 1 - lastPos));
}

void FileStorage::getIntData(const std::string &line, size_t &lastPos, int &data) const
{
    lastPos = line.find(":", lastPos + 1);
    data = std::stoi(line.substr(lastPos + 1, line.find("#", lastPos) - 1 - lastPos));
}

void FileStorage::writeAllAccount()
{
    std::remove(FileName);
    for(const auto &account : accounts)
    {
        writeAccount(account);
    }
}

account FileStorage::FindAccount(int accountNumber) const
{
    for(const auto &account : accounts)
    {
        if(accountNumber == account.getMAccnumber())
        {
            return account;
        }
    }
    account ac(nullptr);
    return ac;
}
