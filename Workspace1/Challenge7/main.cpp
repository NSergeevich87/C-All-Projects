#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

void UI_Base(vector<double> &v);
void working_with_choice(char, vector<double> &v);
void print_numbers(vector<double> &v);
void clear_numbers(vector<double> &v);
void add_number(vector<double> &v);
void mean_value(vector<double> &v);
void smallest_value(vector<double> &v);
void largest_value(vector<double> &v);
void find_number(vector<double> &v);
bool isFind_num(vector<double> &v, double);

int main()
{
    cout << "Welcome to my program!" << endl;
    
    vector<double> numbers { 1.0, 9.0, 8.0, 7.0 };
    
    UI_Base(numbers);
    
    cout << endl;
    return 0;
}

void UI_Base(vector<double> &num)
{
    static char answer {};
    
    while (answer != 'Q')
    {
        
        cout << "\nHere what you can do: " << endl;
        cout << "P - Print numbers";
        cout << "\nC - Clear numbers";
        cout << "\nA - Add a number";
        cout << "\nF - Find a number";
        cout << "\nM - Display mean of the numbers";
        cout << "\nS - Display the smallest number";
        cout << "\nL - Display the largest number";
        cout << "\nQ - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> answer;
        answer = toupper(answer);
        working_with_choice(answer, num);
    }
}

void working_with_choice(char choice, vector<double> &num)
{
    cout << "Your choice is: " << choice << endl;
    switch (choice)
    {
        case 'P':
            print_numbers(num);
            break;
        case 'C':
            clear_numbers(num);
            break;
        case 'A':
            add_number(num);
            break;
        case 'F':
            find_number(num);
            break;
        case 'M':
            mean_value(num);
            break;
        case 'S':
            smallest_value(num);
            break;
        case 'L':
            largest_value(num);
            break;
        case 'Q':
            cout << "Good luck!" << endl;
            cout << "Program shutting down..." << endl;
            break;
        default:
            cout << "Try again!" << endl;
            UI_Base(num);
            break;
    }
}

void print_numbers(vector<double> &num)
{
    cout << "Printing numbers..." << endl;
    cout << "[ ";
    for (double n : num)
        cout << n << " ";
    cout << "]" << endl;
    UI_Base(num);
}

void clear_numbers(vector<double> &num)
{
    cout << "Cleaning your numbers..." << endl;
    num.clear();
    UI_Base(num);
}

void add_number(vector<double> &num)
{
    double add_num {};
    string temp {};
    cout << "Enter number to add: ";
    cin >> temp;
    add_num = stod(temp);
    num.push_back(add_num);
    UI_Base(num);
}

void mean_value(vector<double> &num)
{
    double sum {};
    for (double n : num)
        sum += n;
    cout << "Mean value is: " << sum / num.size() << endl;
    UI_Base(num);
}

void smallest_value(vector<double> &num)
{
    double min {num.at(0)};
    for(auto n : num) if (n < min) min = n;
    cout << "Smallest value is: " << min << endl;
    UI_Base(num);
}

void largest_value(vector<double> &num)
{
    double max {num.at(0)};
    for (auto n : num) if (n > max) max = n;
    cout << "Largest value is: " << max << endl;
    UI_Base(num);
}

void find_number(vector<double> &num)
{
    double target {};
    string temp {};
    cout << "Enter a number to find: ";
    cin >> temp;
    target = stod(temp);
    if (isFind_num(num, target))
        cout << "Number is finded!" << endl;
    else cout << "Number is not finded!" << endl;
}

bool isFind_num(vector<double> &v, double target)
{
    for (auto n : v)
        if (n == target) return true;
    return false;
}