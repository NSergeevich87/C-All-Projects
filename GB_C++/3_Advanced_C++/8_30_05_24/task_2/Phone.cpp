#include "headers/Phone.h"

#include <iostream>

void Phone::call(const std::string& number)
{
    std::cout << "Calling " << number << std::endl;
}

void Phone::sendSMS(const std::string& number, const std::string& message)
{
    std::cout << "Sending SMS to " << number << ": " << message << std::endl;
}