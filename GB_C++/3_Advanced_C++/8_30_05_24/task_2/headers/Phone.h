#pragma once

#include <string>

class Phone
{

public:
    void call(const std::string& number);
    void sendSMS(const std::string& number, const std::string& message);
};