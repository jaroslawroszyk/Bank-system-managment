#include "../include/functiontobank.h"
#include "../include/bank.h"
#define FNAME "data.dat"

void Functionality::writeAccount()
{
    account aco;
    std::ofstream file;
    file.open(FNAME, std::ios::binary | std::ios::app);
    aco.create_acc();
    file.write(reinterpret_cast<char *>(&aco), sizeof(account));
    file.close();
}

void Functionality::displayDetails(int numberAccount)
{

    account aco;
    bool well = false;
    std::ifstream inFile;
    inFile.open(FNAME, std::ios::binary);
    if (!inFile)
    {
        std::cout << "File couldn't be open!!";
        return;
    }

    std::cout << "Details" << std::endl;

    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        if (aco.returnacnumber() == numberAccount)
        {
            aco.showacc();
            well = true;
        }
    }

    inFile.close();
    if (well == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }

}

void Functionality::modifyAccount(int numberAccount)
{
    bool found = false;
    account aco;
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
            std::cout << "MODIFY OLD DETAILS: " << std::endl;
            aco.modify();
            int pos = (-1) * static_cast<int>(sizeof(account));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char *>(&aco), sizeof(account));
            std::cout << "Details have been updated!" << std::endl;
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }
}

void Functionality::deleteAccount(int numberAccount)
{
    account aco;
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
    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        if (aco.returnacnumber() != numberAccount)
        {
            outFile.write(reinterpret_cast<char *>(&aco), sizeof(account));
        }
    }
    inFile.close();
    outFile.close();

    std::remove(FNAME);
    std::rename("Temp.dat", FNAME);
    std::cout << "Deleted!" << std::endl;
}

void Functionality::displayAllAccount()
{
    account aco;
    std::ifstream inFile;
    inFile.open(FNAME, std::ios::binary);
    if (!inFile)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    std::cout << "\tACCOUNT list" << std::endl;
    std::cout << "No    Surname     Name     Type   Balance" << std::endl;
    while (inFile.read(reinterpret_cast<char *>(&aco), sizeof(account)))
    {
        aco.report();
    }
    inFile.close();
}

void Functionality::depositOrWithdraw(int numberAccount, int option)
{
    account aco;
    bool found = false;
    int amount;
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
            if (option == 1)
            {
                std::cout << "Deposit, enter the amount: ";
                std::cin >> amount;
                aco.deposit(amount);
            }
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
    std::system("clear");
}