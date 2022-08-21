#pragma once

class BankOperation
{
    virtual void create_acc() = 0;

    virtual void showacc() const = 0;

    virtual void modify() = 0;

};