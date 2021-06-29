#include "systembank.h"
#include "bank.h"
#include "functiontobank.h"

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
    do
    {
    std::cout << "[1] New account" << std::endl;         //writeacc()
    std::cout << "[2] Deposit amount" << std::endl;      //depositOrWithdraw()
    std::cout << "[3] Withdraw amount" << std::endl;     //depositorWithdraw()
    std::cout << "[4] Balance account" << std::endl;     // display details()
    std::cout << "[5] Account holder list" << std::endl; //displayAllAccount()
    std::cout << "[6] Close account" << std::endl;       //deleteAccount()
    std::cout << "[7] Modify account" << std::endl;      //modifyAccount()
    std::cout << "[8] Exit" << std::endl;
    std::cout << "Select options 1-8: ";
    std::cin >> enter;
     switch (enter)
        {
        case SystemBank::s_newaccount:
        {
            cleaningScreen();
            std::cout << "Creating new account \n";
            writeAccount();
            break;
        }
        case SystemBank::s_deposit:
        {
            cleaningScreen();
            std::cout << "Deposit \n";
            enterAccNo();
            std::cin >> n;
            depositOrWithdraw(n, 1);
            break;
        }
        case SystemBank::s_withdraw:
        {
            cleaningScreen();
            std::cout << "Withdraw \n";
            enterAccNo();
            std::cin >> n;
            depositOrWithdraw(n, 2);
            break;
        }
        case SystemBank::s_balance:
        {
            cleaningScreen();
            std::cout << "Balance \n";
            enterAccNo();
            std::cin >> n;
            displayDetails(n);
            break;
        }
        case SystemBank::s_holder:
        {
            cleaningScreen();
            std::cout << "Account holder list \n";
            displayAllAccount();
            std::cout << "\n\n\n";
            break;
        }
        case SystemBank::s_closeacc:
        {
            cleaningScreen();
            displayAllAccount();
            std::cout << "\n\n";
            std::cout << "Close account! \n";
            enterAccNo();
            std::cin >> n;
            deleteAccount(n);
            break;
        }
        case SystemBank::s_modify:
        {
            cleaningScreen();
            std::cout << "Modify account! \n";
            enterAccNo();
            std::cin >> n;
            modifyAccount(n);
            break;
        }
        case SystemBank::s_exit:
        {
            std::cout << "Bye bye " << std::endl;
            
            break;
        }
        // default:
        // {
        //     std::cout << "Ops! No way!" << std::endl;
        // }
        }
    } while (enter != SystemBank::s_exit);
}