#include "../include/CliInput.h"
#include "../include/Account.h"

int CliInput::getAccountNumber() const
{
    int accountNumber;
    std::cout << "Enter Account number: ";
    std::cin >> accountNumber;

    return accountNumber;
}

std::string CliInput::getSurname() const
{
    std::string surname;
    std::cout << "Enter surname of the Account holder: ";
    std::cin >> surname;
    while (isNumber(surname))
    {
        std::cout << "This is the number of re-enter last name: ";
        std::cin >> surname;
    }
    return surname;
}

std::string CliInput::getName() const
{
    std::string name;
    std::cout << "Enter name of the Account holder: ";
    std::cin >> name;
    while (isNumber(name))
    {
        std::cout << "This is the number of re-enter name: ";
        std::cin >> name;
    }
    return name;
}

char CliInput::getAccountType() const
{
    char type;
    std::cout << "Enter type Account: (S-standard/P-Premium) ";
    std::cin >> type;
    type = toupper(type);
    while (type != 'S' && type != 's' && type != 'P' && type != 'p')
    {
        std::cout << "Invalid data! \n Please enter again: ";
        std::cin >> type;
    }
    return type;
}

int CliInput::getDepositAmount() const
{
    int deposit;
    std::cout << "enter the amount of the first payment(not less than 500) \n";
    std::cin >> deposit;

    while (deposit < 500)
    {
        std::cout << "Less than 500!\n";
        std::cout << "Enter again: ";
        std::cin >> deposit;
    }
    return deposit;
}