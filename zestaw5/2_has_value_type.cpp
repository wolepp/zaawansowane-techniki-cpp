#include <iostream>

using namespace std;

template <typename T>
class has_value_type
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    template <typename U>
    static one test(typename U::value_type);
    
    template <typename U>
    static two test(...);
    
public:
    enum
    {
        yes = (sizeof(test<T>(0)) == sizeof(one))
    };
};

struct Test
{
};

template <typename T>
struct some_trait
{
    typedef T value_type;
};

int main(int argc, char const *argv[])
{

    cout << has_value_type<int>::yes << endl;
    cout << has_value_type<Test>::yes << endl;
    cout << has_value_type<some_trait<int>>::yes << endl;

    return 0;
}
