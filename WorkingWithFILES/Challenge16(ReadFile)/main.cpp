#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    const int field{20};
    const int left_side{10};
    const int right_side{10};
    string compare{};
    string name{};
    string result{};
    int score{};
    int sum{};
    int counter{};
    
    ifstream in_line;
    in_line.open("responses.txt");
	if(!in_line)
    {
        cerr << "Some problem with file" << endl;
        return -1;
    }
    //Получаем первую строчку правильных ответов 5/5
    in_line >> compare;
    
    cout << std::setw((field - 8) / 2) << "" << "Results:\n" << endl;
    cout << std::setw(left_side) << std::left << "Student"
         << std::setw(right_side) << std::right << "Score" << endl;
    cout << std::setfill('-') << std::setw(field) << "" << endl;
    cout << std::setfill(' '); //reset fill
    
    while(!in_line.eof())
    {
        in_line >> name;
        cout << setw(left_side) << left << name;
        in_line >> result;
        for(size_t i = 0; i < result.size(); ++i)
        {
            if(result[i] == compare[i]) score++;
        }
        cout << setw(right_side) << right << score << endl;
        sum += score;
        counter++;
        score = 0;
    }
    
    cout << std::setfill('-') << std::setw(field) << "" << endl;
    cout << std::setfill(' '); //reset fill
    cout << std::setw(left_side) << left << "Average:"
         << std::setw(right_side) << right << (static_cast<double>(sum) / counter) << endl;
    
    in_line.close();
	return 0;
}		