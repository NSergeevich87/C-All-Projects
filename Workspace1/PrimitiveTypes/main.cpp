#include <iostream>

using namespace std;

int main()
{
    char new_char {'N'};
    cout << "My new char is: " << new_char << endl;
    
    unsigned short int score {55};
    int age {65};
    long int people_in_florida {20'056'334};
    long long int distance_to_alpha_centauri {9'461'000'000'000};
    
    cout << "score: " << score << " age: " << age << " people_in_florida: " << people_in_florida << " distance_to_alpha_centauri: " << distance_to_alpha_centauri << endl;
    
    long double veary_large {2.7e120}; //так обозначается степень "e"
    cout << "Veary large: " << veary_large << endl;
    
    return 0;
}