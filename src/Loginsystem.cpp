#include "../include/Loginsystem.h"
#include "../include/BankOptions.h"
#include <thread>
#include <chrono>
#define WORKERSFILE "workers.txt"

bool Login::regstr()
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

std::string Login::getLogin()
{
    std::string login;
    std::cout << "Enter login: ";
    std::cin >> login;
//    setMLogin(login);
    return login;
}

std::string Login::getPassword()
{
    std::string password;
    std::cout << "Enter password: ";
    std::cin >> password;
//    setMPassword(password);
    return password;
}

void Login::setMLogin(const std::string &mLogin)
{
    m_login = mLogin;
}

void Login::setMPassword(const std::string &mPassword)
{
    m_password = mPassword;
}

//repair register
bool Login::Islogin()
{
    std::string lo, po;
    m_login = getLogin();
    m_password = getPassword();

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

std::istream &operator>>(std::istream &in, LoginSystem &entry)
{
    int int_entry;
    entry = (in >> int_entry) ? static_cast<LoginSystem>(int_entry) : LoginSystem::wrong;
    return in;
}

void Login::menuLogin()
{
    LoginSystem entr;
    do
    {
        std::cout << "[1] Register\n";
        std::cout << "[2] Login\n";
        std::cin >> entr;

        switch (entr)
        {
            case LoginSystem::regi:
            {
                std::cout << "Regis\n";
                regstr();
                //isLogin();
                break;
            }
            case LoginSystem::logi:
            {
//            std::system("clear");
                bool is = Islogin();
                if (!is)
                {
                    menuLogin();
                }
                else
                {
                    Operation::menu();
                }
                break;
            }
            default:
            {
                std::cout << "Not defined type\n";
                break;
            }
        }
    } while (entr == LoginSystem::wrong);
}

