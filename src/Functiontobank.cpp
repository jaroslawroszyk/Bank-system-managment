#include "../include/Functiontobank.h"
#include "../include/FileStorage.h"

#define FNAME "data.txt"

void Functionality::writeAccount()
{
    const InputInterface *input = new CliInput;
    Account aco(input);
    aco.create_acc();

    FileStorage storage;
    storage.writeAccount(aco);

    delete input;
}


void Functionality::displayDetails(int numberAccount)
{
    FileStorage storage;
    Account aco = storage.FindAccount(numberAccount);
    std::cout << "Details" << std::endl;

    if (aco.getMAccnumber() != -1)
    {
        aco.raport();
        return;
    }
    std::cout << "Account doesn't exist" << std::endl;
}

void Functionality::modifyAccount(int numberAccount)
{
    FileStorage storage;
    Account aco = storage.FindAccount(numberAccount);
    aco.showacc();
    std::cout << "MODIFY OLD DETAILS: " << std::endl;
    aco.modify();

    storage.modifyAccount(aco);
}

void Functionality::deleteAccount(int numberAccount)
{
    FileStorage storage;
    storage.deleteAccount(numberAccount);

    std::cout << "Deleted!" << std::endl;

}

void Functionality::generateRaport() const
{
    FileStorage storage;
    auto accounts = storage.readAllAccounts();
    for (const auto &account: accounts)
    {
        account.raport();
    }
}

void Functionality::displayAllAccount()
{
    std::cout << "\tACCOUNT list" << std::endl;
    std::cout << "No    Surname     Name     Type   Balance" << std::endl;
    generateRaport();

}

int Functionality::optionDeposit(int option , Account &aco , int amount) const
{
    if (option == 1)
    {
        std::cout << "Deposit, enter the amount: ";
        std::cin >> amount;
        aco.deposit(amount);
    }
    return amount;
}

int Functionality::optionWithdraw(int option , Account &aco , int amount) const
{
    if (option == 2)
    {
        std::cout << "Whitdraw, enter the amount: ";
        std::cin >> amount;
        int balance = aco.returndeposit() - amount;
        if ((balance < 500 && aco.returntype() == 'S') || (balance < 1000 && aco.returntype() == 'P'))
        {
            std::cout << "Insufficiency balance";
        } else
        {
            aco.withdraw(amount);
        }
    }
    return amount;
}

void Functionality::depositOrWithdraw(int numberAccount , int option)
{
    Account aco(nullptr);
    bool found = false;
    int amount = 0;
    std::fstream File;
    File.open(FNAME , std::ios::binary | std::ios::in | std::ios::out);
    if (!File)
    {
        std::cout << "File couldn't be open!!";
        return;
    }
    while (!File.eof() && found == false)
    {
        File.read(reinterpret_cast<char *>(&aco) , sizeof(Account));
        if (aco.returnacnumber() == numberAccount)
        {
            aco.showacc();
            amount = optionDeposit(option , aco , amount);
            amount = optionWithdraw(option , aco , amount);

            int pos = (-1) * static_cast<int>(sizeof(aco));
            File.seekp(pos , std::ios::cur);
            File.write(reinterpret_cast<char *>(&aco) , sizeof(Account));
            std::cout << "successs" << std::endl;
            found = true;
        }
    }
    File.close();
    if (found == false)
    {
        std::cout << "Account doesn't exist" << std::endl;
    }
}

void Functionality::enterAccNo()
{
    std::cout << "Enter Account number: ";
}

void Functionality::cleaningScreen()
{
    std::cout << "\033[2J\033[1;1H";
}