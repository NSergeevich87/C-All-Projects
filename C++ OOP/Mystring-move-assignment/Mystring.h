#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class Mystring
{
private:
    char *str;
    
public:
    Mystring();                       //Constructor
    Mystring(const char *str_val);    //Overload constructor
    Mystring(const Mystring &source); //Deepcopy constructor
    Mystring(Mystring &&source);      //Move constructor
    ~Mystring();                      //Destructor
    
    void display() const;             //Display method
    int get_len() const;              //get_length method
    const char *get_str() const;      //get_str pointer method
    
    Mystring &operator=(const Mystring &rhs); //Overload copy assignment operator =
    Mystring &operator=(Mystring &&rhs);      //Overload move assignment operator =
};

#endif // _MYSTRING_H_
