#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> vector1;
    vector <int> vector2;
    
    vector1.push_back(10);
    vector1.push_back(20);
    
    cout << "Size of vector1 is: " << vector1.size() << endl;
    cout << "Vector1 1: " << vector1.at(0) << endl;
    cout << "Vector1 2: " << vector1.at(1) << endl;
    
    vector2.push_back(100);
    vector2.push_back(200);
    
    cout << "Size of vector2 is: " << vector2.size() << endl;
    cout << "Vector2 1: " << vector2.at(0) << endl;
    cout << "Vector2 2: " << vector2.at(1) << endl;
    
    vector <vector<int>> vector_2d;
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);
    
    cout << "Size of vector_2d is: " << vector_2d.size() << endl;
    
    int size2Dvector = vector_2d.size();
    
    for (int i = 0; i < size2Dvector; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << vector_2d.at(i).at(j) << " ";
        }
    }
    
    vector1.at(0) = 1000;
    
    cout << endl;
    for (int i = 0; i < size2Dvector; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << vector_2d.at(i).at(j) << " ";
        }
    }
    
    cout << "\n" << vector1.at(0) << " " << vector1.at(1) << endl;
    
    return 0;
}