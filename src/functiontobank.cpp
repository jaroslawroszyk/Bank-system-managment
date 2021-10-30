#include "../include/functiontobank.h"
#include "../include/account.h"
#include "bank.h"
#include "CliInput.h"
#define FNAME "data.dat"

void Functionality::writeAccount()
{
    const InputInterface *input = new CliInput;
    account aco(input);
    std::ofstream file;
    file.open(FNAME, std::ios::binary | std::ios::app);
    aco.create_acc();
    file.write(reinterpret_cast<char *>(&aco), sizeof(account));
    file.close();
    delete input;
}

bool Functionality::ifFileIsReading(int numberAccount, account &aco, std::ifstream &inFile) const
{
    bool well;
    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        if (aco.returnacnumber() == numberAccount)
        {
            aco.showacc();
            well = true;
        }
    }
    return well;
}

void Functionality::displayDetails(int numberAccount)
{

    account aco(nullptr);
    bool well = false;
    std::ifstream inFile;
    inFile.open(FNAME, std::ios::binary);
    if (!inFile)
    {
        std::cout << "File couldn't be open!!";
        return;
    }

    std::cout << "Details" << std::endl;

    well = ifFileIsReading(numberAccount, aco, inFile);

    inFile.close();
    if (well == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }

}

bool Functionality::isModify(int numberAccount, account &aco, std::fstream &File) const
{
    bool found;
    File.read(reinterpret_cast<char *>(&aco), sizeof(account));
    if (aco.returnacnumber() == numberAccount)
    {
        aco.showacc();
        std::cout << "MODIFY OLD DETAILS: " << std::endl;
        aco.modify();
        int pos = (-1) * static_cast<int>(sizeof(account));
        File.seekp(pos, std::ios::cur);
        File.write(reinterpret_cast<char *>(&aco), sizeof(account));
        std::cout << "Details have been updated!" << std::endl;
        found = true;
    }
    return found;
}

void Functionality::modifyAccount(int numberAccount)
{
    bool found = false;
    account aco(nullptr);
    std::fstream File;
    File.open(FNAME, std::ios::binary | std::ios::in | std::ios::out);
    if (!File)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    while (!File.eof() && found == false)
    {
        found = isModify(numberAccount, aco, File);
    }
    File.close();
    if (found == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }
}


void Functionality::IfDataIsNotCorrect(int numberAccount, account &aco, std::ifstream &inFile, std::ofstream &outFile) const
{
    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        if (aco.returnacnumber() != numberAccount)
        {
            outFile.write(reinterpret_cast<char *>(&aco), sizeof(account));
        }
    }
}

void Functionality::deleteAccount(int numberAccount)
{
    account aco(nullptr);
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open(FNAME, std::ios::binary);
    if (!inFile)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    outFile.open("Temp.dat", std::ios::binary);
    inFile.seekg(0, std::ios::beg);
    IfDataIsNotCorrect(numberAccount, aco, inFile, outFile);
    inFile.close();
    outFile.close();

    std::remove(FNAME);
    std::rename("Temp.dat", FNAME);
    std::cout << "Deleted!" << std::endl;
}

void Functionality::generateRaport(account &aco, std::ifstream &inFile) const
{
    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        aco.report();
    }
}

void Functionality::displayAllAccount()
{
    account aco(nullptr);
    std::ifstream inFile;
    inFile.open(FNAME, std::ios::binary);
    if (!inFile)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    std::cout << "\tACCOUNT list" << std::endl;
    std::cout << "No    Surname     Name     Type   Balance" << std::endl;
    generateRaport(aco, inFile);
    inFile.close();
}

int Functionality::optionDeposit(int option, account &aco, int amount) const
{
    if (option == 1)
    {
        std::cout << "Deposit, enter the amount: ";
        std::cin >> amount;
        aco.deposit(amount);
    }
    return amount;
}

int Functionality::optionWithdraw(int option, account &aco, int amount) const
{
    if (option == 2)
    {
        std::cout << "Whitdraw, enter the amount: ";
        std::cin >> amount;
        int balance = aco.returndeposit() - amount;
        if ((balance < 500 && aco.returntype() == 'S') || (balance < 1000 && aco.returntype() == 'P'))
        {
            std::cout << "Insufficiency balance";
        }
        else
        {
            aco.withdraw(amount);
        }
    }
    return amount;
}

void Functionality::depositOrWithdraw(int numberAccount, int option)
{
    account aco(nullptr);
    bool found = false;
    int amount = 0;
    std::fstream File;
    File.open(FNAME, std::ios::binary | std::ios::in | std::ios::out);
    if (!File)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&aco), sizeof(account));
        if (aco.returnacnumber() == numberAccount)
        {
            aco.showacc();
            amount = optionDeposit(option, aco, amount);
            amount = optionWithdraw(option, aco, amount);

            int pos = (-1) * static_cast<int>(sizeof(aco));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char *>(&aco), sizeof(account));
            std::cout << "successs" << std::endl;
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }
}

void Functionality::enterAccNo()
{
    std::cout << "Enter account number: ";
}

void Functionality::cleaningScreen()
{
}