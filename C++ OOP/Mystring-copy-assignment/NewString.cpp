#include "NewString.h"

NewString::NewString() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

NewString::NewString(const char *str_val) : str{nullptr}
{
    if (str_val == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(str_val) + 1];
        strcpy(str, str_val);
    }
}

NewString::NewString(const NewString &source) : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

NewString::~NewString()
{
    delete [] str;
}

//Overloading copy assigment operator =
NewString &NewString::operator=(const NewString &rhs)
{
    if (this == &rhs) return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

int NewString::get_len() const
{
    return strlen(str);
}

void NewString::display() const
{
    std::cout << str << " : " << get_len() << std::endl;
}

const char *NewString::get_str() const
{
    return str;
}