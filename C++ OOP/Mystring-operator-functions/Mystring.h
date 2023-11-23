#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class Mystring
{
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);       //Member overload operator == 
    friend Mystring operator-(const Mystring &obj);                         //Member overload operator - (Make lowercase)
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);    //Member overload operator + (Concatenation)
    
private:
    char *str;
    
public:
    Mystring();
    Mystring(const char *str_val);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();
    
    void display() const;
    int get_len() const;
    const char *get_str() const;

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
};

#endif // _MYSTRING_H_
