#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

void display(const array<int, 5> &arr)
{
    cout << "[ ";
    for(const auto &i : arr) cout << i << " ";
    cout << "]" << endl;
}

void display_double(const array<double, 10> &arr)
{
    cout << "[ ";
    for(auto &i : arr) cout << i << " ";
    cout << "]" << endl;
}

void test1()
{
    cout << "\nTest1======================================" << endl;
    
    std::array <int, 5> arr1 { 1, 2, 3, 4, 5 };
    std::array <int, 5> arr2;
    display(arr1);
    display(arr2);
    
    arr2 = { 10, 20, 30, 40, 50 };
    display(arr1);
    display(arr2);
    
    cout << "Size arr1: " << arr1.size() << endl;
    cout << "Size arr2: " << arr2.size() << endl;
    
    arr1[0] = 1000;
    arr1.at(1) = 2000;
    display(arr1);
    
    cout << "Front of arr2: " << arr2.front() << " Back of arr2: " << arr2.back() << endl;
}

void test2()
{
    cout << "\nTest2======================================" << endl;
    
    std::array<int, 5> arr1 { 1, 2, 3, 4, 5 };
    std::array<int, 5> arr2 { 50, 40, 30, 20, 10 };
    display(arr1);
    display(arr2);
    
    arr1.fill(66);
    display(arr1);
    display(arr2);
    
    arr1.swap(arr2);
    display(arr1);
    display(arr2);
}

void test3()
{
    cout << "\nTest3======================================" << endl;
    
    std::array<int, 5> arr1;
    display(arr1);
    arr1.fill(7);
    display(arr1);
    cout << arr1.size() << endl;
    cout << arr1.front() << endl;
    cout << arr1.back() << endl;
    
    int *ptr = arr1.data();
    cout << ptr << endl;
    *ptr = 999;
    display(arr1);
}

void test4()
{
    cout << "\nTest4======================================" << endl;
    
    std::array<double, 10> arr1 { 0.1, 8.37, 5.63, 52.3, 0.18, 2.24, 3.6, 5.0, 3.5, 4.6 };
    display_double(arr1);
    
    //std::sort(arr1.begin(), arr1.end());
    std::sort(begin(arr1), end(arr1));
    display_double(arr1);
}

void test5()
{
    cout << "\nTest5======================================" << endl;
    //find MIN and MAX nums of an array
    std::array<int, 5> arr { 2, 6, 0, 59, 8 };
    sort(begin(arr), end(arr));
    display(arr);
    
    std::array<int, 5>::iterator min_elem = std::min_element(arr.begin(), arr.end());
    cout << "Min_element: " << *min_elem << endl;
    
    std::array<int, 5>::iterator max_elem = std::max_element(begin(arr), end(arr));
    cout << "Max_element: " << *max_elem << endl;
}

void test6()
{
    cout << "\nTest6======================================" << endl;
    //adjacent - соседний повторный элемент
    std::array<int, 5> arr { 1, 2, 3, 3, 3 };
    display(arr);
    
    std::array<int, 5>::iterator adjacent = std::adjacent_find(arr.begin(), arr.end());
    if(adjacent != arr.end())
    {
        cout << "Adjacent_elem was found: " << *adjacent << endl;
    }
    else cout << "Adjacent wasn't found" << endl;
    
}

void test7()
{
    cout << "\nTest7======================================" << endl;
    // accumulate - сложение элементов
    std::array<double, 10> arr { 1.3, 8.37, 5.63, 52.3, 0.1001, 2.24, 3.6, 5.28, 3.5, 4.6 };
    display_double(arr);
    
    double sum = std::accumulate(begin(arr), end(arr), 0.0);
    
    cout << "Summ elem of arr: " << sum << endl;
    
    cout << "Check....." << endl;
    sum = 0;
    for(auto &i : arr)
    {
        sum += i;
    }
    cout << "Summ after checking: " << sum << endl;
}

void test8()
{
    cout << "\nTest8======================================" << endl;
    //count - подсчет кол-ва определенных элементов
    std::array<int, 10> arr { 1, 2, 5, 1, 4, 7, 1, 1, 9, 1 };
    int count = std::count(arr.begin(), arr.end(), 1);
    cout << "Found 1: " << count << endl;
}

void test9()
{
    cout << "\nTest9======================================" << endl;
    // count_if -> with lambda expression
    std::array<int, 10> arr { 1, 2, 4, 8, 10, 20, 100, 200, 350, 500 };
    int count = std::count_if(begin(arr), end(arr), [] (int x) { return x >= 10 && x < 200; }); // 3
    cout << "Count numbers 10 <= x < 200: " << count << endl;
}

int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    //test6();
    //test7();
    //test8();
    test9();
    
    return 0;
}