#include "headers/PhoneBook.h"

void PhoneBook::add(const std::string& name, const std::string& phone)
{
    phoneBook[name] = phone;
}

void PhoneBook::remove(const std::string& name)
{
    phoneBook.erase(name);
}

std::string PhoneBook::getNumber(const std::string& name) const
{
    return phoneBook.at(name);
}