#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
	cout << boolalpha << endl;
	
	Mystring text1;
	Mystring text2 {"text"};
	text2.display();
	Mystring text3 {""};
	
	Mystring text4 {text2};
	text4.display();
	
	text3 = text4;
	text3.display();
	
	text1 = {"UPPER"};
	text1.display();
	text1 = -text1;
	text1.display();
	
	Mystring text5;
	text5 = text1 + text2;
	text5.display();
	
	Mystring text6 {"++++-"};
	text5 += text6;
	text5.display();
	
	cout << (text5 == text6) << endl;
	cout << (text5 != text6) << endl;
	text5 = text6;
	cout << (text5 == text6) << endl;
	cout << (text5 != text6) << endl;
	
	text5 = text1 * 3;
	text5.display();
	
	text5 *= 3;
	text5.display();
	
	text5 = {"jsfkdbryopr"};
	text5.display();
	++text5;
	text5.display();
	text5 = -text5;
	text5.display();
	text5++;
	text5.display();
	
	cout << endl;
	return 0;
}