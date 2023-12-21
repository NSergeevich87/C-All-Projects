#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

string BaseInterface();
bool WordFinder(const string &word, const string &find);
void Conclusion(const int &totalW, const int &targetW, const string &word); 

int main()
{
    string line{};
    string findW{};
    
    int TotalWords{0}; 
    int TargetWords{0};
    
    ifstream in_file;
    in_file.open("RomeoAndJuliet.txt");
    
    if (!in_file)
    {
        cerr << "Some problem with file" << endl;
        return -1;
    }
    else cout << "File ready to read\n" << endl;
    
    findW = BaseInterface(); // Получаем слово для поиска
    
    while(in_file >> line)
    {
        TotalWords++;
        if(WordFinder(line, findW))
        {
            ++TargetWords;
        }
    }
    
    Conclusion(TotalWords, TargetWords, findW);
    
    in_file.close();
    return 0;
}

string BaseInterface()
{
    const int field{50};
    string temp{}; // Переменная для варианта с независимостью регистра
    string word{};
    cout << setw((field - 34) / 2) << "" << "Welcome to the word search program\n" << endl;
    cout << setfill('-') << setw(field) << "" << endl;
    cout << setfill(' ');
    cout << "\nEnter word that you should to find: ";
    cin >> temp;
    
    // Сделаем регистро независимым
    /*for(size_t i = 0; i < temp.size(); ++i)
    {
        word += tolower(temp.at(i));
    }*/
    
    cout << "Your word is: '" << temp << "' - let's find it..." << endl;
    
    return temp;
}

bool WordFinder(const string &word, const string &find)
{
    /*string compare {word};
    string finding {find};
    string editedW{};
    //int targetW{};
    
    for(size_t i = 0; i < compare.size(); ++i)
    {
        if(ispunct(compare.at(i))) break;
        //else editedW += compare.at(i);
        else editedW += tolower(compare.at(i));    // Вариант регистронезависимый
    }
    
    if(editedW == finding) return true;//targetW++;
    
    return false;*/
    
    // second example
    size_t found = word.find(find);
    if (found == string::npos) return false;
    else return true;
}

void Conclusion(const int &totalW, const int &targetW, const string &word)
{
    const int field{50};
    const int left_side{25};
    const int right_side{25};
    
    string tarW {word};
    
    cout << "\n" << setfill('-') << setw(field) << "" << endl;
    cout << setfill(' ');
    
    cout << setw(left_side) << left << "All words:" << setw(right_side) << right << totalW << endl;
    cout << "Target word '" << tarW << "' was found '" << targetW << "' times" << endl;
}