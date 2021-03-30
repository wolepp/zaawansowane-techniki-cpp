#include <iostream>
#include <string>

using namespace std;

// polimorfizm dynamiczny

class Fruit
{
public:
    virtual void decay() = 0;
    virtual ~Fruit(){};
};

class Banana : public Fruit
{
protected:
    int _length;

public:
    Banana(int length) : Fruit(), _length(length){};

    virtual void decay()
    {
        cout << "It's banana " << _length << "cm here. I'm getting brown! Quick, before it's too late!" << endl;
    }
};

class Orange : public Fruit
{
protected:
    int _radius;

public:
    Orange(int radius) : Fruit(), _radius(radius){};

    virtual void decay()
    {
        cout << "Hey, it's orange. I'm going to die soon. Do something. I am only " << _radius << "cm big." << endl;
    }
};

// polimorfizm statyczny
template <typename T>
void decay_all(T table[], size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        table[i]->decay();
    }
}

class NotFruit
{
private:
    string _name;

public:
    NotFruit(string name) : _name(name){};
    void decay()
    {
        cout << "Ha! I am not some common fruit! I am " << _name << "! But I decay as well..." << endl;
    }
};

int main(int argc, char const *argv[])
{
    // polimorfizm dynamiczny

    const size_t n = 4;

    Fruit *fruits[n] =
        {
            new Banana(5),
            new Orange(8),
            new Banana(9),
            new Orange(6)};

    cout << "---------- fruit.decay ----------" << endl;
    for (auto f : fruits)
    {
        f->decay();
    }

    NotFruit *notFruits[] = {new NotFruit("A1"), new NotFruit("B4")};
    cout << "-------- decay_all fruits --------" << endl;
    decay_all(fruits, n);
    cout << "------ decay_all not fruits ------" << endl;
    decay_all(notFruits, 2);

    return 0;
}
