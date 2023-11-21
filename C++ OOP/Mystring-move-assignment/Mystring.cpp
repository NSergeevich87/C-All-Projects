#include "Mystring.h"

Mystring::Mystring() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
    std::cout << "Base constructor was called" << std::endl;
}

Mystring::Mystring(const char *str_val) : str{nullptr}
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
    std::cout << "Overload constructor was called" << std::endl;
}

Mystring::Mystring(const Mystring &source) : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    std::cout << "Deepcopy constructor was called" << std::endl;
}

Mystring::Mystring(Mystring &&source) : str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor was called" << std::endl;
}

Mystring::~Mystring()
{
    if (str == nullptr) std::cout << "Destructor was called for : nullptr" << std::endl;
    else std::cout << "Destructor was called for : " << str << std::endl;
    delete [] str;
}

void Mystring::display() const { std::cout << str << " : " << get_len() << std::endl; }

int Mystring::get_len() const { return strlen(str); }

const char *Mystring::get_str() const { return str; }

Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Copy assignment was called" << std::endl;
    
    if (this == &rhs) return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Move assignment was called" << std::endl;
    
    if (this == &rhs) return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}