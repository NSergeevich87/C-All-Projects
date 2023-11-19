#include "Mystr.h"

//Empty constructor
Mystr::Mystr()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

//Overload constructor
Mystr::Mystr(const char *str_val)
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
    
//Deep copy constructor
Mystr::Mystr(const Mystr &source)
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

Mystr::~Mystr()
{
    delete [] str;
}

//length method
int Mystr::get_len() const
{
    return std::strlen(str);
}

//display method
void Mystr::display() const
{
    std::cout << str << " : " << get_len() << std::endl;
}

//get_str method
const char *Mystr::get_str() const
{
    return str;
}
