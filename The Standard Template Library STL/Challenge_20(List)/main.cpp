#include <iostream>
#include <algorithm>
#include <list>
#include <iomanip>
#include <string>
#include <cctype>
#include <limits>

using namespace std;

class Song
{
    friend ostream &operator<<(ostream &os, const Song &s);
    string name{};
    string singer{};
    int rating{};
    
    public:
        Song() = default;
        Song(string name_v, string singer_v, int rating_v) : name{name_v}, singer{singer_v}, rating{rating_v} {}
        
        string get_name() const { return name; }
        string get_singer() const { return singer; }
        int get_rating() const { return rating; }
        
        bool operator<(const Song &rhs) const
        {
            return this->rating < rhs.rating;
        }
        
        bool operator==(const Song &rhs) const
        {
            return (this->name == rhs.name && this->singer == rhs.singer && this->rating == rhs.rating);
        }
};

ostream &operator<<(ostream &os, const Song &s)
{
    os << setw(15) << right << s.name 
       << setw(15) << right << s.singer 
       << setw(8)  << right << s.rating;
    return os;
}

void print_nemu()
{
    cout << "\n" << setw(15) << left << "F - Play First Song" << "\n"
         << setw(15) << left << "N - Play Next song"  << "\n"
         << setw(15) << left << "P - Play Previous song"  << "\n"
         << setw(15) << left << "A - Add and play a new Song at current location"  << "\n"
         << setw(15) << left << "L - List the current playlist"  << "\n"
         << "===============================================" << "\n"
         << setw(15) << left << "Enter a selection (Q to quit): ";
}

void play_first_song(list<Song> &songs, list<Song>::iterator &i)
{
    auto it = songs.begin();
    i = songs.begin();
    
    while(it != songs.end())
    {
        if (it == i)
        {
            cout << "Play -> " << *i << endl;
            ++it;
        }
        cout << setw(8) << "" << *it << endl;
        ++it;
    }
}

void play_next_song(list<Song> &songs, list<Song>::iterator &i)
{
    auto it = songs.begin();
    if(*i == songs.back()) i = songs.begin();
    else ++i;
    
    while(it != songs.end())
    {
        if (it == i)
        {
            cout << "Play -> " << *i << endl;
            ++it;
        }
        else
        {
            cout << setw(8) << "" << *it << endl;
            ++it;
        }
    }
}

void play_previous_song(list<Song> &songs, list<Song>::iterator &i)
{
    auto it = songs.begin();
    if(i != songs.begin()) i--;
    else advance(i, songs.size() - 1);
    
    while(it != songs.end())
    {
        if(it == i)
        {
            cout << "Play -> " << *i << endl;
            ++it;
        }
        else
        {
            cout << setw(8) << "" << *it << endl;
            ++it; 
        }
    }
}

void work_with_answer(list<Song> &songs, list<Song>::iterator &i, const char l)
{
    switch(l)
    {
        case 'F':
            cout << "\n" << setw(30) << right << "F - Play First Song" << endl; // field 47
            play_first_song(songs, i);
            break;
        case 'N':
            cout << "\n" << setw(30) << right << "N - Play Next song" << endl;
            play_next_song(songs, i);
            break;
        case 'P':
            cout << "\n" << setw(30) << right << "P - Play Previous song" << endl;
            play_previous_song(songs, i);
            break;
        case 'A':
            cout << "\n" << setw(30) << right << "A - Add and play a new Song at current location" << endl;
            break;
        case 'L':
            cout << "\n" << setw(40) << right << "L - List the current playlist" << endl;
            break;
        case 'Q':
            cout << "Q - quit" << endl;
            break;
        default: cout << "\n" << setw(30) << right << "Incorrect! Try again!" << endl;
    }
}

int main()
{
    char answer{};
    
    list<Song> my_songs
    {
        {"name1", "singer1", 4},
        {"name2", "singer2", 5},
        {"name3", "singer3", 3},
        {"name4", "singer4", 4},
        {"name5", "singer5", 5}
    };
    
    list<Song>::iterator it = my_songs.begin();
    
    do
    {
        print_nemu();
        cin >> answer;
        answer = toupper(answer);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        work_with_answer(my_songs, it, answer);
    }
    while(answer != 'Q');
        
    cout << "See you soon...." << endl;
    
    return 0;
}