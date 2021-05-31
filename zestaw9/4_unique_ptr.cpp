#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Person
{
public:
    string _name;
    int _age;

    Person(string name = "None", int age = 0) : _name(name), _age(age){};
};


int main(int argc, char const *argv[])
{
    unique_ptr<Person> pPerson = make_unique<Person>("Imię", 22);

    unique_ptr<Person[]> pPeople = make_unique<Person[]>(3);

    for (int i = 0; i < 3; i++)
    {
        pPeople[i]._name = "Numer " + to_string(i);
        pPeople[i]._age = 30 + 5 * i;
        cout << pPeople[i]._name << ", wiek " << pPeople[i]._age << endl;
    }

    return 0;
}
