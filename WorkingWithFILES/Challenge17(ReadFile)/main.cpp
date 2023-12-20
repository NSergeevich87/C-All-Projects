#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

string BaseInterface();
int WordFinder(const string &word, const string &find);
void Conclusion(const int &totalW, const int &targetW); 

int main()
{
    string line{};
    string findW{};
    
    int TotalWords{}; 
    int TargetWords{};
    
    ifstream in_file;
    in_file.open("RomeoAndJuliet.txt");
    
    if (!in_file)
    {
        cerr << "Some problem with file" << endl;
        return -1;
    }
    else cout << "File ready to read\n" << endl;
    
    findW = BaseInterface(); // Получаем слово для поиска
    
    while(!in_file.eof())
    {
        in_file >> line;
        TotalWords++;
        TargetWords += WordFinder(line, findW);
    }
    
    Conclusion(TotalWords, TargetWords);
    
    in_file.close();
    return 0;
}

string BaseInterface()
{
    const int field{50};
    //const int left_side{25};
    //const int right_side{25};
    string word{};
    cout << setw((field - 34) / 2) << "" << "Welcome to the word search program\n" << endl;
    cout << setfill('-') << setw(field) << "" << endl;
    cout << setfill(' ');
    cout << "\nEnter word that you should to find: ";
    cin >> word;
    cout << "Your word is: " << word << " - let's find it..." << endl;
    
    return word;
}

int WordFinder(const string &word, const string &find)
{
    string compare {word};
    string finding {find};
    string editedW{};
    int TargetWords{};
    
    for(size_t i = 0; i < compare.size(); ++i)
    {
        if(compare.at(i) != '.' || compare.at(i) != ',')
        {
            editedW += compare.at(i);
        }
    }
    
    if(editedW == finding) ++TargetWords;
    
    return TargetWords;
}

void Conclusion(const int &totalW, const int &targetW)
{
    cout << endl;
    cout << "All words: " << totalW << endl;
    cout << "Target words: " << targetW << endl;
}