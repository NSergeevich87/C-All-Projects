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
    std::cout << "Move constructor called" << std::endl;
}

Mystring::~Mystring()
{
    if (str == nullptr) std::cout << "Distructor for nullptr" << std::endl;
    else std::cout << "Distructor for : " << str << std::endl;
    delete [] str;
}

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

void Mystring::display() const { std::cout << str << " : " << get_len() << std::endl; }
int Mystring::get_len() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
    return (strcmp(lhs.str, rhs.str) == 0);
}

Mystring operator-(const Mystring &obj)
{
    char *text = new char[strlen(obj.str) + 1];
    
    strcpy(text, obj.str);
    
    for (size_t i=0; i<strlen(text); i++) text[i] = tolower(text[i]);
    
    Mystring temp {text};
    
    delete [] text;
    
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
    char *text = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    
    strcpy(text, lhs.str);
    strcat(text, rhs.str);
    
    Mystring temp {text};
    
    delete [] text;
    
    return temp;
}