#include "functiontobank.h"
#include "bank.h"
#define FNAME "data.dat"

void writeAccount() //in file! save data on file .dat
{
    account aco;
    std::ofstream file;
    file.open(FNAME, std::ios::binary | std::ios::app);
    aco.create_acc();
    file.write(reinterpret_cast<char *>(&aco), sizeof(account));
    file.close();
}

void displayDetails(int n) //displaying details by account number (FILE)
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
        if (aco.returnacnumber() == n)
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

void modifyAccount(int n) //modify account by account number (FILE)
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
        if (aco.returnacnumber() == n)
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

void deleteAccount(int n) //delete account by account number(FILE)
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
        if (aco.returnacnumber() != n)
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

void displayAllAccount() //displaying all acount from file
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

void depositOrWithdraw(int n, int op)
{
    account aco;
    bool found = false;
    int ammount;
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
        if (aco.returnacnumber() == n)
        {
            aco.showacc();
            if (op == 1)
            {
                std::cout << "Deposit, enter the ammount: ";
                std::cin >> ammount;
                aco.deposit(ammount);
            }
            if (op == 2)
            {
                std::cout << "Whitdraw, enter the ammount: ";
                std::cin >> ammount;
                int balance = aco.returndeposit() - ammount;
                if ((balance < 500 && aco.returntype() == 'S') || (balance < 1000 && aco.returntype() == 'P'))
                {
                    std::cout << "Insufficience balance";
                }
                else
                {
                    aco.withdraw(ammount);
                }
            }
            int pos = (-1) * static_cast<int>(sizeof(aco));
            File.seekp(pos, std::ios::cur);
            File.write(reinterpret_cast<char *>(&aco), sizeof(account));
            std::cout << "sucess" << std::endl;
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        std::cout << "account doesn't exist" << std::endl;
    }
}

void enterAccNo()
{
    std::cout << "Enter account number: ";
}

void cleaningScreen()
{
    system("clear");
}