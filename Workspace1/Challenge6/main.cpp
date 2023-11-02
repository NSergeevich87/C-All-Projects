#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    bool stop {false};
    vector<unsigned> secret_num {};
                    //01234567890123456789012345678901234567890123456789012
    string alphabet {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz 1234567890'"};
    string encrypt_alphabet {"1v`2y!3w~4q@5z #6j$7J\%U8^9&0*ñ´()-_=+/.?><,':;|}{][ZAQWSXGFTRE"};
//======================================================================================    
    do 
    {
        cout << "\n=================================" << endl;
        
        secret_num.clear();
        cout << "Enter a message to encrypt: ";
        string message {};
        getline(cin, message);
        for (unsigned i {0}; i < message.length(); ++i)
        {
            for (unsigned j {0}; j < alphabet.length(); ++j)
            {
                if (message[i] == alphabet[j]) secret_num.push_back(j);
            }
        }
        cout << "\nYour message is encrypted: ";
        string message_encrypted {};
        for (unsigned i{0}; i < secret_num.size(); ++i)
        {
            for (unsigned j{0}; j < encrypt_alphabet.size(); ++j)
            {
                if (secret_num[i] == j) message_encrypted += encrypt_alphabet[j];
            }
        }
        cout << message_encrypted << endl;
//======================================================================================        
        cout << "\nDo you want decrypt this message? Yes/No: ";
        string ans {};
        getline(cin, ans);
        for (unsigned c{0}; c < ans.length(); ++c)
        {
            ans[c] = toupper(ans[c]);
        }  
        if (ans == "YES")
        {
            cout << "\nDecrypting..." << endl;
            secret_num.clear();
            message.clear();
            cout << "\nSecret number should be empty: " << secret_num.size() << endl;
            cout << "Message should be empty: " << message.length() << endl;
            cout << "\nYour message is decrypted: ";
            for (unsigned i{0}; i < message_encrypted.size(); ++i)
            {
                for (unsigned j{0}; j < encrypt_alphabet.size(); ++j)
                {
                    if (message_encrypted[i] == encrypt_alphabet[j]) secret_num.push_back(j);
                }
            }
            for (unsigned i{0}; i < secret_num.size(); ++i)
            {
                for (unsigned j{0}; j < alphabet.size(); ++j)
                {
                    if (secret_num[i] == j) message += alphabet[j];
                }
            }
            cout << message << endl;
        }
//======================================================================================
        string answer {};
        do {
            cout << "\nDo you want to encrypt another message? Yes/No: ";
            getline(cin, answer);
            for (size_t i{0}; i < answer.length(); ++i)
            {
                answer.at(i) = toupper(answer.at(i));
            }
            if (answer == "NO") stop = true;
            else if (answer == "YES") cout << "\nLet's do it!" << endl;
            else cout << "\nTry again" << endl;
        } while (answer != "YES" && answer != "NO");
        
        cout << "\n=================================" << endl;
    }
    while (!stop);
    cout << "\nProgram shutdown process..." << endl;
//======================================================================================    
    cout << endl;
    return 0;
}