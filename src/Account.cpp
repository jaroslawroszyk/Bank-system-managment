#include "../include/Account.h"
#define FNAME "data.txt"

//creating Interfaces and replacing void functions to returning something
//REFACTOR THIS PIECE OF SHIT
auto Account::create_acc() -> void
{
    std::ifstream checkid;
    checkid.open(FNAME, std::ios::binary | std::ios::app);
    m_accnumber = input->getAccountNumber();
    m_surname = input ->getSurname();
    m_name = input->getName();
    m_type = input ->getAccountType();
    m_deposit = input->getDepositAmount();
}

auto Account::showacc() const -> void
{
    std::cout << "\n";
    std::cout << "Account number: " << m_accnumber << "\n";
    std::cout << "Account holder surname: " << m_surname << "\n";
    std::cout << "Account holder name: " << m_name << "\n";
    std::cout << "Type of Account: " << m_type << "\n";
    std::cout << "Available balance: " << m_deposit << "\n";
}

auto Account::modify() -> void //to powinno zwrocic zmodyfikowane konto
{
    std::cout << "!Modify!\n";
    std::cout << "Account number: " << m_accnumber << "\n";
    std::cout << "Modify surname of the Account holder: ";
    std::cin.ignore();
    std::cin >> m_surname;
    std::cout << "Modify name of the Account holder: ";
    std::cin.ignore();
    std::cin >> m_name;

    std::cout << "Modify Type of Account: ";
    std::cin >> m_type;
    m_type = toupper(m_type);
    std::cout << "Modify Balance: ";
    std::cin >> m_deposit;
}

auto Account::deposit(int deposit) -> void
{
    m_deposit += deposit;
}

auto Account::withdraw(int deposit) -> void
{
    m_deposit -= deposit;
}

auto Account::raport() const -> void
{
    std::cout << m_accnumber << std::setw(4) << "" << m_surname << std::setw(8)
              << " " << m_name << std::setw(9) << std::setw(6) << "" << m_type
              << " " << std::setw(9) << m_deposit << std::endl;
}

auto Account::returnacnumber() const -> int
{
    return m_accnumber;
}

auto Account::returndeposit() const -> int
{
    return m_deposit;
}

auto Account::returntype() const -> char
{
    return m_type;
}

auto Account::getMAccnumber() const -> int
{
    return m_accnumber;
}

auto Account::getMName() const -> const std::string&
{
    return m_name;
}

auto Account::getMSurname() const -> const std::string&
{
    return m_surname;
}

auto Account::getMDeposit() const -> int
{
    return m_deposit;
}

auto Account::getMType() const -> char
{
    return m_type;
}

auto Account::setMAccnumber(int mAccnumber) -> void
{
    m_accnumber = mAccnumber;
}

auto Account::setMName(const std::string &mName) -> void
{
    m_name = mName;
}

auto Account::setMSurname(const std::string &mSurname) -> void
{
    m_surname = mSurname;
}

auto Account::setMDeposit(int mDeposit) -> void
{
    m_deposit = mDeposit;
}

auto Account::setMType(char mType) -> void
{
    m_type = mType;
}