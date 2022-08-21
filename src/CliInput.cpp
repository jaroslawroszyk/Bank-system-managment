#include "../include/CliInput.h"

auto ClInput::getAccountNumber() const -> int
{
    int accountNumber;
    std::cout << "Enter Account number: ";
    std::cin >> accountNumber;

    return accountNumber;
}

auto ClInput::getSurname() const -> std::string
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

auto ClInput::getName() const -> std::string
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

auto ClInput::getAccountType() const -> char
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

auto ClInput::getDepositAmount() const -> int
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