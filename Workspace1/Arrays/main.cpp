#include <iostream>

using namespace std;

int main()
{
    char letras[] {'a','b','c','d','e'};
    cout << "first elem is: " << letras[0] << endl;
    cout << "last elem is: " << letras[4] << endl;
    
    double temperature[] {45.4, 34.6, 77.8, 29.7};
    cout << "Temp of first is: " << temperature[0] << endl;
    
    temperature[0] += 4.6;
    cout << "New temp of first is: " << temperature[0] << endl;
    
    int test_scores [5] {1, 2, 3, 4, 5};
    cout << "\n1st score is: " << test_scores[0] << endl;
    cout << "\n2st score is: " << test_scores[1] << endl;
    cout << "\n3st score is: " << test_scores[2] << endl;
    cout << "\n4st score is: " << test_scores[3] << endl;
    cout << "\n5st score is: " << test_scores[4] << endl;
    
    cout << "\nEnter 5 scores: ";
    cin >> test_scores[0];
    cin >> test_scores[1];
    cin >> test_scores[2];
    cin >> test_scores[3];
    cin >> test_scores[4];
    
    cout << "\n1st score is: " << test_scores[0] << endl;
    cout << "\n2st score is: " << test_scores[1] << endl;
    cout << "\n3st score is: " << test_scores[2] << endl;
    cout << "\n4st score is: " << test_scores[3] << endl;
    cout << "\n5st score is: " << test_scores[4] << endl;
    
    cout << "\nNotice what the valut of the array name is: " << test_scores << endl;
    
    //Enter multi-dimencional array
    
    int array[2][3]
    {
        2, 4, 6,
        5, 7, 9
    };
    
    cout << "Number 1: " << array[0][0] << "Number  6: " << array[1][2] << endl;
    
    return 0;
}