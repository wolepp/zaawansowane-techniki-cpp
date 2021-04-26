#include <iostream>
#include <vector>

using namespace std;

template <typename T, typename U>
class Is_convertible
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    static one test(U);
    static two test(...);
    static T makeT();

public:
    enum
    {
        yes = (sizeof(test(makeT())) == sizeof(one)),
        same_type = false
    };
};

template <typename T>
class Is_convertible<T, T>
{
public:
    enum
    {
        yes = true,
        same_type = true
    };
};

int main(int argc, char const *argv[])
{
    cout << "int ~> double: ";
    cout << Is_convertible<int, double>::yes << endl;

    cout << "double ~> int: ";
    cout << Is_convertible<double, int>::yes << endl;

    cout << "int == double: ";
    cout << Is_convertible<int, double>::same_type << endl;
    cout << "size_t == unsigned long: ";
    cout << Is_convertible<size_t, unsigned long>::same_type << endl;

    cout << "vector<double>::value_type == double: ";
    cout << Is_convertible<vector<double>::value_type, double>::same_type << endl;
    cout << "vector<double>::iterator == double * : ";
    cout << Is_convertible<vector<double>::iterator, double *>::same_type << endl;

    return 0;
}
