#ifndef _MYSTR_H_
#define _MYSTR_H_

#include <iostream>
#include <cstring>

class Mystr
{
private:
    char *str;
    
public:
    //Constructor
    Mystr();
    //Overload Constructor
    Mystr(const char *str_val);
    //Deep Copy Constructor
    Mystr(const Mystr &source);
    //Destructor
    ~Mystr();
    //Display Metod
    void display() const;
    //Get string Metod
    const char *get_str() const;
    //Get length Metod
    int get_len() const;

};

#endif // _MYSTR_H_
