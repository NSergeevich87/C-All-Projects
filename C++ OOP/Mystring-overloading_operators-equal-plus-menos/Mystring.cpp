#include "Mystring.h"

Mystring::Mystring()
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
    if (str == nullptr) std::cout << "nullptr destructor" << std::endl;
    else std::cout << "nullptr destructor for : " << str << std::endl;
    delete [] str;
}

void Mystring::display() const { std::cout << str << " " << get_len() << std::endl; }

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

bool Mystring::operator==(const Mystring &rhs) const
{
    return (strcmp(str, rhs.str) == 0);
}

Mystring Mystring::operator-() const
{
    char *text = new char[strlen(str) + 1];
    strcpy(text, str);
    
    for (size_t i = 0; i < strlen(text); ++i)
    {    
        text[i] = tolower(text[i]);
    }
    
    Mystring temp {text};
    
    delete [] text;
    
    return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
    char *text = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(text, str);
    strcat(text, rhs.str);
    
    Mystring temp {text};
    
    delete [] text;
    
    return temp;
}