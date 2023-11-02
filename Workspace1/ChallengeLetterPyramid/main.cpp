#include <iostream>
#include <string>

using namespace std;

int main()
{
    string selection {};
    string message {};
    int num_of_message {};
    int num_of_space {};
    
    do 
    {
        cout << "==========================================" << endl;
        
        message.clear();
        cout << "Enter message for pyramid: ";
        cin >> message;
        num_of_message = message.length();
        //cout << "\n" << message.length() << endl;
        for (int i{0}; i < num_of_message; ++i)
        {
            if (i < num_of_message)
            {
                for (int j{1}; j < num_of_message - i; ++j)
                {
                    cout << " ";
                }
                num_of_space = i + 1;
            }
            for (int k{0}; k < num_of_space; ++k)
            {
                cout << message[k];
            }
            //cout << num_of_space << endl;
            //========
            if (i > 0)
            {
                for (int f {i - 1}; f >= 0; --f)
                {
                    cout << message[f];
                }
            }
            //========
            cout << endl;
        }
        
        
        cout << "==========================================" << endl;
        cout << "Start one more time? (Y/N) : ";
        cin >> selection;
    } while (selection != "N" && selection != "n");
    cout << "Closing program..." << endl;
    
    cout << endl;
    return 0;
}