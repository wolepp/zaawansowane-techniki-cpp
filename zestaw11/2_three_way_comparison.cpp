#include <iostream>

class MyInt
{
    int _value;

public:
    MyInt(int value) : _value{value} {}

    std::strong_ordering operator<=>(MyInt const &rhs)
    {
        return _value <=> rhs._value;
    }
};


int main(int argc, char const *argv[])
{
    MyInt x = MyInt(10);
    MyInt y = MyInt(20);

    if (x < y)
    {
        std::cout << "x mniejsze niż y" << std::endl;
    }
    else if (x > y)
    {
        std::cout << "y mniejsze niż x" << std::endl;
    }
    else
    {
        std::cout << "równe" << std::endl;
    }

    return 0;
}
