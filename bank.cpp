#include "bank.h"

bool isNumber(const std::string &s)
{
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

//second version
// bool isNumber(std::string s)
// {
//     for (int i = 0; i < s.length(); i++)
//         if (isdigit(s[i]) == false)
//             return false;

//     return true;
// }

void account::create_acc()
{
    std::ifstream checkid;
    checkid.open("data.dat",std::ios::binary | std::ios::app);
    std::cout << "Enter account number: ";
    std::cin >> m_accnumber;

    // m_accnumber++;

    std::cout << "Enter surname of the account holder: ";
    std::cin.ignore();
    std::cin.getline(m_surname, 50);
    // std::cin >> m_surname;

    while (isNumber(m_surname))
    {
        std::cout << "This is the number of re-enter last name: ";
        std::cin >> m_surname;
    }

    std::cout << "Enter name of the account holder: ";
    std::cin.ignore();
    std::cin.getline(m_name, 50);
    // std::cin >> m_name;
    while (isNumber(m_name))
    {
        std::cout << "This is the number of re-enter  name: ";
        std::cin >> m_name;
    }

    std::cout << "Enter type account: (S-standard/P-Premium) ";
    std::cin >> m_type;
    m_type = toupper(m_type);

    while (m_type != 'S' && m_type != 's' && m_type != 'P' && m_type != 'p')
    {
        std::cout << "Invalid data! \n Please enter again: ";
        std::cin >> m_type;
    }

    std::cout << "enter the amount of the first payment(not less than 500) \n";
    std::cin >> m_deposit;

    while (m_deposit < 500)
    {
        std::cout << "Less than 500!\n";
        std::cout << "Enter again: ";
        std::cin >> m_deposit;
    }
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
    // std::cin.getline(m_surname, 50);
    std::cin >> m_surname;
    std::cout << "Modify name of the account holder: ";
    std::cin.ignore();
    // std::cin.getline(m_name, 50);
    std::cin >> m_name;

    std::cout << "Modify Type of Account: ";
    std::cin >> m_type;
    m_type = toupper(m_type);
    std::cout << "Modify Balance: ";
    std::cin >> m_deposit;
}

void account::deposit(int depo)
{
    m_deposit += depo;
}

void account::withdraw(int depo)
{
    m_deposit -= depo;
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

