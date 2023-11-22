#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class Mystring
{
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

    Mystring &operator=(const Mystring &rhs);      //Overload operator assignment, constructor COPY
    Mystring &operator=(Mystring &&rhs);           //Overload operator assignment, constructor MOVE
    
    Mystring operator-() const;                    //Overload operator - (Make lowercase)
    Mystring operator+(const Mystring &rhs) const; //Overload operator + (concatenate)
    bool operator==(const Mystring &rhs) const;    //Overload operator ==
};

#endif // _MYSTRING_H_
