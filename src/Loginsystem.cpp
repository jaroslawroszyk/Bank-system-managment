#include "../include/LoginSystem.h"
#include "../include/BankOptions.h"
#include <thread>
#include <chrono>
#define WORKERSFILE "workers.txt"

auto Login::regstr() -> bool
{
    std::string login, password, l, p;
    std::cout << "Enter Login: ";
    std::cin >> login;
    std::cout << "Enter Password: ";
    std::cin >> password;

    std::ofstream regist(WORKERSFILE, std::ios::app);
    regist << login << ' ' << password << std::endl;
    regist.close();
    return true;
}

auto Login::setLogin() -> std::string
{
    std::string login;
    std::cout << "Enter login: ";
    std::cin >> login;
    return login;
}

auto Login::setPassword() -> std::string
{
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
    return password;
}

//repair register
auto Login::Islogin() -> bool
{
    std::string lo, po;
    m_login = setLogin();
    m_password = setPassword();

    std::ifstream inp(WORKERSFILE);
    while (inp >> lo >> po)
    {
        if (lo == getLog() && po == getPas())
        {
            std::cout << "Login suc! \n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "\033[2J\033[1;1H"; //clear the screen
            return true;
        }
    }
    inp.close();
    return false;
}

std::istream &operator>>(std::istream &in, loginInformation &entry)
{
    int int_entry;
    entry = (in >> int_entry) ? static_cast<loginInformation>(int_entry) : loginInformation::wrong;
    return in;
}

void Login::menuLogin()
{
    loginInformation loginOption;
    do
    {
        std::cout << "[1] Register\n";
        std::cout << "[2] Login\n";
        std::cin >> loginOption;

        switch (loginOption)
        {
            case loginInformation::registration:
            {
                std::cout << "Regis\n";
                regstr();
                //isLogin();
                break;
            }
            case loginInformation::login:
            {
                bool is = Islogin();
                if (!is)
                {
                    menuLogin();
                }
                else
                {
                    menu();
                }
                break;
            }
            default:
            {
                std::cout << "Not defined type\n";
                break;
            }
        }
    } while (loginOption == loginInformation::wrong);
}

