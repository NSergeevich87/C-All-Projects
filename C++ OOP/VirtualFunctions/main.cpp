// Polymorphismo, Dynamic binding, Virtual Functions, references and pointers
#include <iostream>
#include <vector>

using namespace std;

class Account
{
    public:
        virtual void withdraw(double amount) const
        {
            cout << "Account withdraw method" << endl;
        }
        
        virtual ~Account(){
            
        }
};

class Savings : public Account
{
    public:
        virtual void withdraw(double amount) const
        {
            cout << "Savings withdraw method" << endl;
        }
        
        virtual ~Savings(){
            
        }
};

class Chacking : public Account
{
    public:
        virtual void withdraw(double amount) const override
        {
            cout << "Chacking withdraw method" << endl;
        }
            
        virtual ~Chacking(){
            
        }
};

class Trust : public Account
{
    public:
        virtual void withdraw(double amount) const
        {
            cout << "Trust withdraw method" << endl;
        }
        
        virtual ~Trust(){
            
        }
};

int main()
{
    Account *a1 = new Account();
    Account *a2 = new Savings();
    Account *a3 = new Chacking();
    Account *a4 = new Trust();
    
    a1->withdraw(50);
    a2->withdraw(50);
    a3->withdraw(50);
    a4->withdraw(50);
    
    vector <Account *> vec {a1, a2, a3, a4};
    for(auto vector_acc : vec)
        vector_acc->withdraw(100);
    
    Account *arr[] = {a1, a2, a3, a4};
    for(auto i = 0; i < 4; i++)
        arr[i]->withdraw(55);
    
    delete a1;
    delete a2;
    delete a3;
    delete a4;
    
    cout << endl;
    return 0;
}