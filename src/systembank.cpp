#include "../include/systembank.h"
#include "../include/account.h"
#include "../include/functiontobank.h"

std::istream &operator>>(std::istream &in, SystemBank &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<SystemBank>(int_entry) : SystemBank::s_exit;
    return in;
}

void menu()
{
    int n;
    SystemBank enter;
    Functionality fun;
    do
    {
        std::cout << "[1] New account" << std::endl;
        std::cout << "[2] Deposit amount" << std::endl;
        std::cout << "[3] Withdraw amount" << std::endl;
        std::cout << "[4] Balance account" << std::endl;
        std::cout << "[5] Account holder list" << std::endl;
        std::cout << "[6] Close account" << std::endl;
        std::cout << "[7] Modify account" << std::endl;
        std::cout << "[8] Exit" << std::endl;
        std::cout << "Select options 1-8: ";
        std::cin >> enter;
        switch (enter)
        {
        case SystemBank::s_newaccount:
        {

            fun.cleaningScreen();
            std::cout << "Creating new account \n";
            fun.writeAccount();
            break;
        }
        case SystemBank::s_deposit:
        {
            fun.cleaningScreen();
            std::cout << "Deposit \n";
            fun.enterAccNo();
            std::cin >> n;
            fun.depositOrWithdraw(n, 1);
            break;
        }
        case SystemBank::s_withdraw:
        {
            fun.cleaningScreen();
            std::cout << "Withdraw \n";
            fun.enterAccNo();
            std::cin >> n;
            fun.depositOrWithdraw(n, 2);
            break;
        }
        case SystemBank::s_balance:
        {
            fun.cleaningScreen();
            std::cout << "Balance \n";
            fun.enterAccNo();
            std::cin >> n;
            fun.displayDetails(n);
            break;
        }
        case SystemBank::s_holder:
        {
           fun.cleaningScreen();
            std::cout << "Account holder list \n";
            fun.displayAllAccount();
            std::cout << "\n\n\n";
            break;
        }
        case SystemBank::s_closeacc:
        {
            fun.cleaningScreen();
            fun.displayAllAccount();
            std::cout << "\n\n";
            std::cout << "Close account! \n";
            fun.enterAccNo();
            std::cin >> n;
            fun.deleteAccount(n);
            break;
        }
        case SystemBank::s_modify:
        {
            fun.cleaningScreen();
            std::cout << "Modify account! \n";
            fun.enterAccNo();
            std::cin >> n;
            fun.modifyAccount(n);
            break;
        }
        case SystemBank::s_exit:
        {
            std::cout << "Bye bye " << std::endl;

            break;
        }
        }
    } while (enter != SystemBank::s_exit);
}