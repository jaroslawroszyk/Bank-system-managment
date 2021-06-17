#include "loginsystem.h"

bool regstr()
{
    std::string login, password, l, p;
    std::cout << "Enter Login: ";
    std::cin >> login;
    std::cout << "Enter Password: ";
    std::cin >> password;

    std::ofstream regist("workers.txt", std::ios::app);
    regist << login << ' ' << password << std::endl;
    regist.close();
    return true;
}

bool login()
{
    int c;
    std::string login, password, l, p;
    std::cout << "Enter login: ";
    std::cin >> login;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::ifstream inp("workers.txt");
    while (inp >> l >> p)
    {
        if (l == login && p == password)
        {
            c = 1;
            std::cout << "login succes!";
        }
    }
    inp.close();
    if (c == 1)
    {
        std::cout << "Login succes! " << std::endl;
        return true;
    }
    else
    {
        std::cout << "NOPE!";
        return false;
    }
    return false;
}

std::istream &operator>>(std::istream &in, LoginSystem &entry)
{
    int int_entry;
    entry = (in >> int_entry) ? static_cast<LoginSystem>(int_entry) : LoginSystem::wrong;
    return in;
}

void menuLogin()
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
            // break;
        }
        case LoginSystem::logi:
        {
            std::cout << "logi\n";

            bool stat = login();
            if (!stat)
            {
                std::cout << "False login!" << std::endl;
                break;
            }
            else
            {
                std::cout << "Succesfully logged in!" << std::endl;
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