#include "../include/loginsystem.h"
#define WORKERSFILE "workers.txt"
bool regstr()
{
    std::string login, password, l, p;
    std::cout << "Enter Login: ";
    std::cin >> login;
    std::cout << "Enter Password: ";
    std::cin >> password;

    std::ofstream regist(WORKERSFILE, std::ios::app);
    regist << login << ' ' << password << std::endl;
    // regist << "Login: " << login << " ,Password: " <<  password << std::endl;
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
    std::ifstream inp(WORKERSFILE);
    while (inp >> l >> p)
    {
        if (l == login && p == password)
        {
            c = 1;
            std::cout << "login succes!";
        }
    }

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
    inp.close();
    return true;
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
            system("clear");
            std::cout << "logi\n";

            bool stat = login();
            if (!stat)
            {
                std::cout << "False login!" << std::endl;
                menuLogin();
            }
            else
            {
                std::cout << "Succesfully logged in!" << std::endl;
                system("clear");
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