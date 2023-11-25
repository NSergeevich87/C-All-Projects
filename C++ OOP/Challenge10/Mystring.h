#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <iostream>
#include <cstring>

class Mystring
{
private:
    char *str;
    
public:
    Mystring();                       //base constructor
    Mystring(const char *str_val);    //overload constructor
    Mystring(const Mystring &source); //deep copy constructor
    Mystring(Mystring &&source);      //move constructor
    ~Mystring();                      //destructor
    
    void display() const;
    int get_len() const;
    const char *get_str() const;

    Mystring &operator=(const Mystring &rhs); //Overload operator assignment, constructor COPY
    Mystring &operator=(Mystring &&rhs);      //Overload operator assignment, constructor MOVE
    
    //Other overload operators
    Mystring operator-() const;                 //tolower
    bool operator==(const Mystring &rhs) const; //equals
    bool operator!=(const Mystring &rhs) const; //No equals
    bool operator<(const Mystring &rhs) const;  //less than
    bool operator>(const Mystring &rhs) const;  //returns true if the lhs string is lexically greater than the rhs string
};

#endif // _MYSTRING_H_
