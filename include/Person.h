#pragma once

#include "CliInput.h"
#include "BankOperation.h"

class Person
{

protected:
    std::string m_name;
    std::string m_surname;
public:
    [[nodiscard]] const std::string &getMName() const;

    [[nodiscard]] const std::string &getMSurname() const;

    void setMName(const std::string &mName);

    void setMSurname(const std::string &mSurname);
};