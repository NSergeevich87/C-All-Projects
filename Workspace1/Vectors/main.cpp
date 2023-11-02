#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> numbers { 80, 70, 69, 34 };
    
    cout << "vector last: " << numbers.at(3) << endl;
    numbers.push_back(77);
    cout << "vector last: " << numbers.at(4) << endl;
    
    vector <char> letras {'a', 'b', 'c', 'd', 'e'};
    cout << letras[0] << endl;
    cout << letras[4] << endl;
    
    vector <int> numbers2 (3, 100); //3 elements all initialized to 100
    cout << numbers2[1] << endl;
    cout << numbers2.size() << endl;
    
    cout << numbers2.at(0) << endl;
    cout << numbers2.at(1) << endl;
    cout << numbers2.at(2) << endl;
    
    cout << "Enter new 3 numbers: ";
    cin >> numbers2.at(0);
    cin >> numbers2[1];
    cin >> numbers2.at(2);
    
    cout << numbers2.at(0) << endl;
    cout << numbers2.at(1) << endl;
    cout << numbers2.at(2) << endl;
    
    vector <vector<int>> double_vector
    {
        {1, 2, 3},
        {3, 2, 1},
        {9, 9, 9} 
    };
    
    cout << double_vector[0][2] << endl;
    cout << double_vector.at(2).at(0) << endl;
    
    vector <int> vec { 10, 20, 30, 40, 50 };
    vec.at(0) = 100;
    int last_index = vec.size() - 1;
    vec.at(last_index) = 1000;
    
    return 0; 
}