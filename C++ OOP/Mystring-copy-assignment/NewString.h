#ifndef _NEWSTRING_H_
#define _NEWSTRING_H_

#include <cstring>
#include <iostream>

class NewString
{
private:
    char *str;
    
public:
    //Empty constructor
    NewString();
    //Overload constructor
    NewString(const char *str_val);
    //Deep copy constructor
    NewString(const NewString &source);
    //Destructor
    ~NewString();
    
    //Display method
    void display() const;
    //Get length method
    int get_len() const;
    //Get str value
    const char *get_str() const;
    
    //Overloading operator =
    NewString &operator=(const NewString &rhs);

};

#endif // _NEWSTRING_H_
