#pragma once

class OutputInterface
{
public:
    virtual ~OutputInterface() = default;

    virtual auto displayAllAccount()->void = 0;

    virtual auto generateRaport() const->void = 0;

private:
};