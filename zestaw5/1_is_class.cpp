#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Is_class
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    template <typename U>
    static one test(int U::*);
    
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

int main(int argc, char const *argv[])
{
    cout << Is_class<int>::yes << endl;
    cout << Is_class<Test>::yes << endl;
    cout << Is_class<stack<int>>::yes << endl;

    return 0;
}
