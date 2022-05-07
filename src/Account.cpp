#include "../include/Account.h"
#define FNAME "data.txt"

//creating Interfaces and replacing void functions to returning something
//REFACTOR THIS PIECE OF SHIT
void Account::create_acc()
{
    std::ifstream checkid;
    checkid.open(FNAME, std::ios::binary | std::ios::app);
    m_accnumber = input->getAccountNumber();
    m_surname = input ->getSurname();
    m_name = input->getName();
    m_type = input ->getAccountType();
    m_deposit = input->getDepositAmount();

}

void Account::showacc() const
{
    std::cout << "\n";
    std::cout << "Account number: " << m_accnumber << "\n";
    std::cout << "Account holder surname: " << m_surname << "\n";
    std::cout << "Account holder name: " << m_name << "\n";
    std::cout << "Type of Account: " << m_type << "\n";
    std::cout << "Available balance: " << m_deposit << "\n";
}

void Account::modify()
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

void Account::deposit(int deposit)
{
    m_deposit += deposit;
}

void Account::withdraw(int deposit)
{
    m_deposit -= deposit;
}

void Account::raport() const
{
    std::cout << m_accnumber << std::setw(4) << "" << m_surname << std::setw(8)
              << " " << m_name << std::setw(9) << std::setw(6) << "" << m_type
              << " " << std::setw(9) << m_deposit << std::endl;
}

int Account::returnacnumber() const
{
    return m_accnumber;
}

int Account::returndeposit() const
{
    return m_deposit;
}

char Account::returntype() const
{
    return m_type;
}

int Account::getMAccnumber() const
{
    return m_accnumber;
}

const std::string &Account::getMName() const
{
    return m_name;
}

const std::string &Account::getMSurname() const
{
    return m_surname;
}

int Account::getMDeposit() const
{
    return m_deposit;
}

char Account::getMType() const
{
    return m_type;
}

void Account::setMAccnumber(int mAccnumber)
{
    m_accnumber = mAccnumber;
}

void Account::setMName(const std::string &mName)
{
    m_name = mName;
}

void Account::setMSurname(const std::string &mSurname)
{
    m_surname = mSurname;
}

void Account::setMDeposit(int mDeposit)
{
    m_deposit = mDeposit;
}

void Account::setMType(char mType)
{
    m_type = mType;
}
