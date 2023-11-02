#include <iostream>

using namespace std;

int main()
{
    bool Stop {false};
    while (!Stop)
    {
        int Score {};
        cout << "Enter how score you have: ";
        cin >> Score;
        char letter_grade {};
        
        if (Score >= 0 && Score <= 100)
        {
            if (Score >= 90) letter_grade = 'A';
            else if (Score >= 80) letter_grade = 'B';
            else if (Score >= 70) letter_grade = 'C';
            else if (Score >= 60) letter_grade = 'D';
            else letter_grade = 'F';
            
            cout << "Your letter is: " << letter_grade << endl;
            
            if (letter_grade == 'F') cout << "Sorry, you must repeat the class" << endl;
            else cout << "Congrats!" << endl;  
        }
        else
        {
            cout << "Sorry this score " << Score << " in not in range" << endl;
        }
        
        cout << "Let's try more? (y/n)";
        char ans {};
        cin >> ans;
        if (ans == 'n') Stop = true;
    }
    
    cout << endl;
    return 0;
}