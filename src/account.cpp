#include "../include/account.h"
#define FNAME "data.dat"

//creating Interfaces and replacing void functions to returning something
//REFACTOR THIS PIECE OF SHIT
void account::create_acc()
{
    std::ifstream checkid;
    checkid.open(FNAME, std::ios::binary | std::ios::app);
    m_accnumber = input->getAccountNumber();
    m_surname = input ->getSurname();
    m_name = input->getName();
    m_type = input ->getAccountType();
    m_deposit = input->getDepositAmount();

}

void account::showacc() const
{
    std::cout << "\n";
    std::cout << "Account number: " << m_accnumber << "\n";
    std::cout << "Account holder surname: " << m_surname << "\n";
    std::cout << "Account holder name: " << m_name << "\n";
    std::cout << "Type of Account: " << m_type << "\n";
    std::cout << "Available balance: " << m_deposit << "\n";
}

void account::modify()
{
    std::cout << "!Modify!\n";
    std::cout << "Account number: " << m_accnumber << "\n";
    std::cout << "Modify surname of the account holder: ";
    std::cin.ignore();
    std::cin >> m_surname;
    std::cout << "Modify name of the account holder: ";
    std::cin.ignore();
    std::cin >> m_name;

    std::cout << "Modify Type of Account: ";
    std::cin >> m_type;
    m_type = toupper(m_type);
    std::cout << "Modify Balance: ";
    std::cin >> m_deposit;
}

void account::deposit(int deposit)
{
    m_deposit += deposit;
}

void account::withdraw(int deposit)
{
    m_deposit -= deposit;
}

void account::report() const
{
    std::cout << m_accnumber << std::setw(4) << "" << m_surname << std::setw(8)
              << " " << m_name << std::setw(9) << std::setw(6) << "" << m_type
              << " " << std::setw(9) << m_deposit << std::endl;
}

int account::returnacnumber() const
{
    return m_accnumber;
}

int account::returndeposit() const
{
    return m_deposit;
}

char account::returntype() const
{
    return m_type;
}

