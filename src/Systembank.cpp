#include "../include/BankOptions.h"
#include "../include/Account.h"
#include "../include/Functiontobank.h"
#include "../include/Options.h"

std::istream &operator>>(std::istream &in , Operation::BankOptions &enter)
{
    int int_entry;
    enter = (in >> int_entry) ? static_cast<Operation::BankOptions>(int_entry) : Operation::BankOptions::s_exit;
    return in;
}

void showOptionInMenu()
{
    std::cout << "[1] New Account" << std::endl;
    std::cout << "[2] Deposit amount" << std::endl;
    std::cout << "[3] Withdraw amount" << std::endl;
    std::cout << "[4] Balance Account" << std::endl;
    std::cout << "[5] Account holder list" << std::endl;
    std::cout << "[6] Close Account" << std::endl;
    std::cout << "[7] Modify Account" << std::endl;
    std::cout << "[8] Exit" << std::endl;
    std::cout << "Select options 1-8: ";
}

void menu()
{
    int n;
    Operation::BankOptions enter;
    FunctionalityForAccount fun;
    do
    {
        showOptionInMenu();
        std::cin >> enter;
        switch (enter)
        {
            case Operation::BankOptions::s_newaccount:
            {
                Options::cleaningScreen();
                std::cout << "Creating new Account \n";
                fun.writeAccount();
                break;
            }
            case Operation::BankOptions::s_deposit:
            {
                Options::cleaningScreen();
                std::cout << "Deposit \n";
                fun.enterAccNo();
                std::cin >> n;
                fun.depositOrWithdraw(n , 1);
                break;
            }
            case Operation::BankOptions::s_withdraw:
            {
                Options::cleaningScreen();
                std::cout << "Withdraw \n";
                fun.enterAccNo();
                std::cin >> n;
                fun.depositOrWithdraw(n , 2);
                break;
            }
            case Operation::BankOptions::s_balance:
            {
                Options::cleaningScreen();
                std::cout << "Balance \n";
                fun.enterAccNo();
                std::cin >> n;
                fun.displayDetails(n);
                break;
            }
            case Operation::BankOptions::s_holder:
            {
                Options::cleaningScreen();
                std::cout << "Account holder list \n";
                fun.displayAllAccount();
                std::cout << "\n\n\n";
                break;
            }
            case Operation::BankOptions::s_closeacc:
            {
                Options::cleaningScreen();
                fun.displayAllAccount();
                std::cout << "\n\n";
                std::cout << "Close Account! \n";
                fun.enterAccNo();
                std::cin >> n;
                fun.deleteAccount(n);
                break;
            }
            case Operation::BankOptions::s_modify:
            {
                Options::cleaningScreen();
                std::cout << "Modify Account! \n";
                fun.enterAccNo();
                std::cin >> n;
                fun.modifyAccount(n);
                break;
            }
            case Operation::BankOptions::s_exit:
            {
                std::cout << "Bye bye " << std::endl;
                break;
            }
            default:
            {
                std::cout << "Error";
            }
        }
    } while (enter != Operation::BankOptions::s_exit);
}