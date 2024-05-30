#pragma once

#include <string>
#include <vector>
#include <map>

class PhoneBook
{
private:
    std::map<std::string, std::string> phoneBook;

public:
    void add(const std::string& name, const std::string& phone);
    void remove(const std::string& name);
    std::string getNumber(const std::string& name) const;
};