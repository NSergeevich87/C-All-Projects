#include "Mystring.h"

//Base constructor
Mystring::Mystring() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
    
    std::cout << "Base constructor was colled" << std::endl;
}

//Overload constructor
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
    
    std::cout << "Overload constructor was called" << std::endl;
}

//Deepcopy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr}
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    
    std::cout << "Deepcopy constructor was called" << std::endl;
}

//Move constructor
Mystring::Mystring(Mystring &&source) : str(source.str)
{
    source.str = nullptr;
    std::cout << "Move constructor was called" << std::endl;
}

//Destructor
Mystring::~Mystring()
{
    if (str == nullptr) std::cout << "Destructor for nullptr" << std::endl;
    else std::cout << "Destructor for " << str << std::endl;
    delete [] str;
}

void Mystring::display() const { std::cout << str << " : " << get_len() << std::endl; }
int Mystring::get_len() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

//Overload operator assignment, constructor COPY
Mystring &Mystring::operator=(const Mystring &rhs)
{
    std::cout << "Overload operator assignment, constructor COPY" << std::endl;
    
    if (this == &rhs) return *this;
    
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

//Overload operator assignment, constructor MOVE
Mystring &Mystring::operator=(Mystring &&rhs)
{
    std::cout << "Overload operator assignment, constructor MOVE" << std::endl;
    
    if (this == &rhs) return *this;
    
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

//Overload operator - (tolower)
Mystring Mystring::operator-() const
{
    std::cout << "Overload operator - (tolower)" << std::endl;
    
    char *text_temp = new char[strlen(str) + 1];
    strcpy(text_temp, str);
    
    for (size_t i=0; i<strlen(text_temp); i++)
    {
        text_temp[i] = tolower(text_temp[i]);
    }
    
    Mystring temp_str {text_temp};
    delete [] text_temp;
    return temp_str;
}

//Overload operator ==
bool Mystring::operator==(const Mystring &rhs) const
{
    return strcmp(str, rhs.str) == 0;
}

//Overload operator !=
bool Mystring::operator!=(const Mystring &rhs) const
{
    return strcmp(str, rhs.str) != 0;
}

//Overload operator <
bool Mystring::operator<(const Mystring &rhs) const
{
    if (strlen(str) < strlen(rhs.str)) return true;
    return false;
}

//Overload operator > (returns true if the lhs string is lexically greater than the rhs string)
//a b c d e f g h i j k l m n o p q r s t u v w x y z
bool Mystring::operator>(const Mystring &rhs) const
{
    //int num1 = str[0];
    //int num2 = rhs.str[0];
    //std::cout << num1 << " : " << num2 << std::endl;
    return (str[0] > rhs.str[0]) == 0;
}

//Overload operator + (concatenation)
Mystring Mystring::operator+(const Mystring &rhs) const
{
	char *text = new char[strlen(str) + strlen(rhs.str) + 1];
	strcpy(text, str);
	strcat(text, rhs.str);
	Mystring temp{text};
	delete [] text;
	return temp;
}

//Overload operator += (concatenation)
Mystring &Mystring::operator+=(const Mystring &rhs)
{
	*this = *this + rhs;
	
	return *this;
}

//Overload operator * (repeat -  results in a string that is copied n times)
Mystring Mystring::operator*(int rhs) const
{
	Mystring temp;
	
	for (int i=1; i<=rhs; i++)
	{
		temp = temp + *this;
	}
	
	return temp;
	
	/*if (rhs == 0)
	{
		Mystring temp;
		return temp;
	}
	
	size_t size = strlen(str) * rhs + 1;
	char *text = new char[size];
	
	strcpy(text, str);
	
	for (int i=1; i<rhs; i++) strcat(text, str);
	
	Mystring temp{text};
	delete [] text;
	return temp;*/
}

//Overload operator *= (repeat the string on the lhs n times and store the result back in the lhs object)
Mystring &Mystring::operator*=(int rhs)
{
	*this = *this * rhs;
	return *this;
	/*if (rhs == 0)
	{
		delete [] str;
		strcpy(str, "");
		return *this;
	}
	
	char *text = new char[strlen(str) * rhs + 1];
	
	strcpy(text, str);
	for (int i = 1; i < rhs; i++) strcat(text, str);
	
	strcpy(str, text);
	delete [] text;
	return *this;*/
}

Mystring &Mystring::operator++()
{
	std::cout << "pre_increment was called" << std::endl;
	
	if (str == nullptr) return *this;
	
	for (size_t i=0; i<strlen(str); i++) str[i] = toupper(str[i]);
	
	return *this;
}

Mystring Mystring::operator++(int)
{
	std::cout << "post_increment was called" << std::endl;
	
	Mystring temp{*this};
	
	operator++();
	
	return temp;
}

Mystring &Mystring::operator--()
{
	if (str == nullptr) return *this;
	
	for (size_t i=0; i<strlen(str); i++) str[i] = tolower(str[i]);
	
	return *this;
}

Mystring Mystring::operator--(int)
{
	Mystring temp{*this};
	
	operator--();
	
	return temp;
}