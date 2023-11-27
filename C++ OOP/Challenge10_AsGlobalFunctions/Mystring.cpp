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

Mystring::Mystring(const Mystring &rhs) : str{nullptr}
{
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
}

Mystring::Mystring(Mystring &&rhs) : str(rhs.str)
{
	rhs.str = nullptr;
}

Mystring::~Mystring()
{
	delete [] str;
}

void Mystring::display() const { std::cout << str << " : " << get_len() << std::endl; }
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

Mystring operator-(const Mystring &obj)
{
	char *text = new char[strlen(obj.str) + 1];
	
	strcpy(text, obj.str);
	
	for (size_t i=0; i<strlen(text); i++)
	{
		text[i] = tolower(text[i]);
	}
	
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

Mystring &operator+=(Mystring &lhs, const Mystring &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs)
{
	return (!strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs)
{
	return (strcmp(lhs.str, rhs.str) > 0);
}

Mystring operator*(const Mystring &lhs, const int rhs)
{
	Mystring temp;
	for (int i=0; i<rhs; i++) temp = temp + lhs;
	return temp;
}

Mystring &operator*=(Mystring &lhs, const int rhs)
{
	lhs = lhs * rhs;
	return lhs;
}

Mystring &operator++(Mystring &obj)
{
	for (size_t i=0; i<strlen(obj.str); i++) obj.str[i] = toupper(obj.str[i]);
	return obj;
}

void operator++(Mystring &obj, int)
{
	//Mystring temp {obj};
	++obj;
	//return temp;
}

std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
	os << rhs.str;
	return os;
}

std::istream &operator>>(std::istream &is, Mystring &rhs)
{
	char *text = new char[1000];
	is >> text;
	rhs = Mystring{text};
	delete [] text;
	return is;
}