#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Song
{
public:
    string _title;
    string _author;

    Song(string title, string author) : _title(title), _author(author)
    {
        cout << "konstruktor, title = " << title << endl;
    };

    ~Song()
    {
        cout << "destruktor, title = " << _title << endl;
    }
};

class Dd
{
public:
    int _dd;
    Dd() {
        _dd = 3;
    };
};

unique_ptr<Song> SongFactory(std::string title, std::string author)
{
    return make_unique<Song>(title, author);
}

void songVector()
{
    vector<unique_ptr<Song>> songs;

    songs.push_back(SongFactory("Zitti E Buoni", "Måneskin"));
    songs.push_back(SongFactory("Coraline", "Måneskin"));
    songs.push_back(SongFactory("Lividi sui gomiti", "Måneskin"));
    songs.push_back(SongFactory("In nome del padre", "Måneskin"));
    songs.push_back(SongFactory("For Your Love", "Måneskin"));

    // nie przez referencje jest błąd
    for (const auto &song : songs)
    {
        cout << "Author: " << song->_author << " Title: " << song->_title << endl;
    }
}

int main(int argc, char const *argv[])
{
    songVector();

    return 0;
}
