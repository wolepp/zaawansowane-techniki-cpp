#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
using namespace std::placeholders;

template <typename T>
class SequenceGen
{
private:
    T _start;
    T _step;

public:
    SequenceGen(T start = T(), T step = 1) : _start(start), _step(step){};

    T operator()()
    {
        T tmp = _start;
        _start += _step;
        return tmp;
    }
};


int main(int argc, char const *argv[])
{
    const size_t n = 20;
    vector<int> v(n);

    generate_n(v.begin(), n, SequenceGen<int>(1, 2));

    for (auto it: v)
    {
        cout << it << " ";
    }
    cout << endl;

    // szukanie pierwszego elementu > 4

    // przez bind
    auto it1 = find_if(v.begin(), v.end(), bind(greater(), _1, 4));
    // przez lambde
    auto it2 = find_if(v.begin(), v.end(), [] (const auto& a) { return a > 4; } );

    cout << "First greater than 4 [bind]: " << *it1 << endl;
    cout << "First greater than 4 [lambda]: " << *it2 << endl;

    return 0;
}
