#include <iostream>
#include <memory>

using namespace std;

class Song
{
private:
    string _title;
    string _author;

public:
    Song(string title, string author)
    {
        _title = title;
        _author = author;
    };
};

int main(int argc, char const *argv[])
{
    Song *ptr= new Song("Chciałem być", "Krzysztof Krawczyk");
    unique_ptr<Song> unique_ptr(new Song("Mój przyjacielu", "Krzysztof Krawczyk"));
    shared_ptr<Song> shared_ptr(new Song("Bo jesteś ty", "Krzysztof Krawczyk"));

    cout << "Size of pointer:    " << sizeof(ptr) << "b" << endl;
    cout << "Size of unique_ptr: " << sizeof(unique_ptr) << "b" << endl;
    cout << "Size of shared_ptr: " << sizeof(shared_ptr) << "b" << endl;

    delete ptr;

    return 0;
}
