#include "Mystring.h"

Mystring::Mystring() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
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
}

Mystring::Mystring(const Mystring &source) : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) : str(source.str)
{
    source.str = nullptr;
}

Mystring::~Mystring()
{
    if (str == nullptr) std::cout << "Destructor for nullptr" << std::endl;
    else std::cout << "Destructor for : " << str << std::endl;
    delete [] str;
}

void Mystring::display() const { std::cout << str << " : " << get_len() << std::endl; }
int Mystring::get_len() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

Mystring &Mystring::operator=(const Mystring &rhs)
{
    if (this == &rhs) return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
    if (this == &rhs) return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &is, Mystring &rhs)
{
    char *text = new char[1000];
    is >> text;
    rhs = Mystring {text};
    delete [] text;
    return is;
}