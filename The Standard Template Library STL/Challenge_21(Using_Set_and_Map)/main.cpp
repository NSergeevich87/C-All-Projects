#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

string clear_line(const string &s)
{
    string line{};
    
    for(char c: s)
    {
        if(c == '.' || c == ',' || c == ';' || c == ':') continue;
        else line += c;
    }
    
    return line;
}

void display(const map<string, int> &m)
{
    cout << setw(12) << left << "\nWord"
         << setw(7) << right << "Count" << endl;
    cout << "===========================" << endl;
    for(auto i: m)
    {
        cout << setw(12) << left << i.first
             << setw(7) << right << i.second << endl;
    }
}

void display(const map<string, set<int>> &m)
{
    cout << setw(13) << left << "\nWord"
         << "Occurrences" << endl;
    cout << "==========================================" << endl;
    
    for(auto pair: m)
    {
        cout << setw(13) << left << pair.first << left << "[ ";
        for(auto i: pair.second) cout << i << " "; 
        cout << "]" << endl;
    }
}

void part1()
{
    string line {};
    map<string, int> word_counter {};
    
    ifstream file {"words.txt"};
    
    if(file)
    {
        cout << "File -> OK" << endl;
        
        while(file >> line)
        {
            line = clear_line(line);
            
            map<string, int>::iterator it = word_counter.find(line);
            
            if(it != end(word_counter))
            {
                word_counter[it->first] += 1;
                it++;
            }
            else
            {
                word_counter.insert(make_pair(line, 1));
                it++;
            }
        }
        
        file.close();
        display(word_counter);
    }
    else cerr << "Error opening input file" << endl;
}

void part2()
{
    string line {};
    string word {};
    map<string, set<int>> words_lines {};
    
    ifstream in_file {"Words.txt"};
    
    if(in_file)
    {
        cout << "File -> OK" << endl;
        
        while(!in_file.eof())
        {
            getline(in_file, line);
            istringstream iss{line};
            iss >> word;
            cout << word << endl;
            
        }
        
    }
    else cout << "Error opening input file" << endl;
}

int main()
{
    //part1();
    part2();
    return 0;
}