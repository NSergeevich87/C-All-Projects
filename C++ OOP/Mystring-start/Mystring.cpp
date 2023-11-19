#include "Mystring.h"
#include <iostream>
#include <cstring>

Mystring::Mystring() 
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

Mystring::Mystring(const char *str_val)
    : str{nullptr} {
        if (str_val == nullptr)
        {
            str = new char[1];
            *str = '\0';
        }
        else
        {
            str = new char[std::strlen(str_val) + 1];
            std::strcpy(str, str_val);
        }
    }

Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

Mystring::~Mystring()
{
    delete [] str;
}

void Mystring::display() const
{
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const
{
    return std::strlen(str);
}

const char *Mystring::get_str() const
{
    return str;
}


