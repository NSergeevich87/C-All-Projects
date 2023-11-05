#include <iostream>

using namespace std;

void print(const int *const arr, const size_t);
int *apply_all(const int *const arr1, const size_t, const int *const arr2, const size_t);

int main()
{
    int arr1[] { 1, 2, 3, 4, 5 };
    int arr2[] { 10, 20, 30 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "Array_1: ";
    print(arr1, size1);
    
    cout << "Array_2: ";
    print(arr2, size2);
    
    int *results = apply_all(arr1, size1, arr2, size2);
    int size = size1 * size2;
    cout << "\n=============================================" << endl;
    cout << "New array: ";
    print(results, size);
    
    delete [] results;
    
    cout << endl;
    return 0;
}

void print(const int *const arr, const size_t size)
{
    cout << "[ ";
    for ( size_t i{0}; i < size; ++i)
    {
        cout << *(arr + i) << " ";
    }
    cout << "]" << endl;
}

int *apply_all(const int *const arr1, const size_t size1, const int *const arr2, const size_t size2)
{
    int counter {0};
    int *new_array { nullptr };
    new_array = new int [size1 * size2];
    
    for ( size_t i{0}; i < size2; ++i)
    {
        for ( size_t j{0}; j < size1; ++j)
        {
            *(new_array + counter) = arr2[i] * arr1[j];
            counter++;
        }
    }
    
    return new_array;
}