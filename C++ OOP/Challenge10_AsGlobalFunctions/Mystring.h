#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <cstring>
#include <iostream>

class Mystring
{
	// - + += == != < > * *= ++ << >>
	friend Mystring operator-(const Mystring &obj);
	friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
	friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);
	friend bool operator==(const Mystring &lhs, const Mystring &rhs);
	friend bool operator!=(const Mystring &lhs, const Mystring &rhs);
	friend bool operator<(const Mystring &lhs, const Mystring &rhs);
	friend bool operator>(const Mystring &lhs, const Mystring &rhs);
	friend Mystring operator*(const Mystring &lhs, const int rhs);
	friend Mystring &operator*=(Mystring &lhs, const int rhs);
	friend Mystring &operator++(Mystring &obj);
	friend void operator++(Mystring &obj, int);
	friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
	friend std::istream &operator>>(std::istream &is, Mystring &rhs);
	
private:
	char *str;
	
public:
	Mystring();
	Mystring(const char *str_val);
	Mystring(const Mystring &source);
	Mystring(Mystring &&source);
	~Mystring();
	
	Mystring &operator=(const Mystring &rhs);
	Mystring &operator=(Mystring &&rhs);
	
	void display() const;
	int get_len() const;
	const char *get_str() const;

};

#endif // _MYSTRING_H_
