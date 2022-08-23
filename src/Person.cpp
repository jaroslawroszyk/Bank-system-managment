#include "../include/Account.h"
#include "../include/Person.h"

auto Person::getMName() const -> const std::string&
{
    return m_name;
}

auto Person::getMSurname() const -> const std::string&
{
    return m_surname;
}

auto Person::setMName(const std::string &mName) -> void
{
    m_name = mName;
}

auto Person::setMSurname(const std::string &mSurname) -> void
{
    m_surname = mSurname;
}