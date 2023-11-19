#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
private:
    char *str{};    //pointer to a char[] that holds a C-style string

public:
    Mystring();                           //No args constructor
    Mystring(const char *str_val);        //Overload constructor
    Mystring(const Mystring &source);     //Copy constructor
    ~Mystring();                          //Destructor
    //Display and Getters
    void display() const;
    int get_length() const;
    const char *get_str() const;

};

#endif // _MYSTRING_H_
