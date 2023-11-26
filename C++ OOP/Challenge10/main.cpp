#include <iostream>
#include "Mystring.h"
#include <vector>

using namespace std;

int main()
{
    cout << boolalpha << endl;
    cout << "=================================================================" << endl;
    
    Mystring text1;
    Mystring text2{"Nikita"};
    text2.display();
    
    cout << "=================================================================" << endl;
    //test deepcopy constructor
    Mystring text3 {text2};
    
    cout << "=================================================================" << endl;
    //test move constructor
    vector<Mystring> textVector;
    textVector.push_back(Mystring{"Nikita"});
    textVector.push_back(Mystring{"Kseniia"});
    textVector.push_back(Mystring{"Daniil"});
    
    cout << "=================================================================" << endl;
    //test overload operator = 
    text1.display();
    text1 = text2;
    text1.display();
    
    cout << "=================================================================" << endl;
    //test overload operator - (tolower)
    Mystring text4 {"O ALL LARGE LETRAS?"};
    text4.display();
    text4 = -text4;
    text4.display();
    
    cout << "=================================================================" << endl;
    //test overload operator ==
    cout << (text1 == text2) << endl;
    cout << (text1 == text4) << endl;
    
    cout << "=================================================================" << endl;
    //test overload operator !=
    cout << (text1 != text2) << endl;
    cout << (text1 != text4) << endl;
    
    cout << "=================================================================" << endl;
    //test overload operator <
    cout << text4.get_len() << " < " << text1.get_len() << endl;
    cout << (text4 < text1) << endl;
    
    cout << "=================================================================" << endl;
    //test overload operator > (returns true if the lhs string is lexically greater than the rhs string)
    text1.display();
    text4.display();
    cout << (text4 > text1) << endl;
	
	cout << "=================================================================" << endl;
	//test overload operator + (concatenation)
	Mystring text5;
	text5 = text1 + " " + text4;// + textVector[1];
	text5.display();
	
	cout << "=================================================================" << endl;
	//test overload operator += (concatenation)
	text1 += " + ";
	text1 += textVector[1];
	text1 += " = LOVE";
	text1.display();
	
	cout << "=================================================================" << endl;
	//test overload operator * (repeat -  results in a string that is copied n times)
	text5 = text1 * 3;
	//text5 = text1 * 0;
	text5.display();
    
	cout << "=================================================================" << endl;
	//test overload operator *= (repeat the string on the lhs n times and store the result back in the lhs object)
	Mystring text6 {"Strong "};
	text6 *= 3;
	text6.display();
	text6 *= 0;
	text6.display();
	
	cout << "=================================================================" << endl;
	//test pre-increment ++ operator
	Mystring text7 {"Some_text"};
	++text7;
	text7.display();
	
	cout << "=================================================================" << endl;
	//test post-increment ++ operator 
	//НЕ РАБОТАЕТ
	--text7;
	text7.display();
	text7++;
	text7.display();
	
	cout << "=================================================================" << endl;
	//test pre-decrement -- operator
	--text7;
	text7.display();
	
	cout << "=================================================================" << endl;
	//test post-decrement -- operator
	//НЕ РАБОТАЕТ
	++text7;
	text7.display();
    text7--;
	text7.display();
	
	
    cout << endl;
    return 0;
}