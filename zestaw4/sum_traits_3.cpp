#include <iostream>

using namespace std;

template <typename T>
struct sum_traits;

template <>
struct sum_traits<char>
{
    typedef int sum_type;
};

template <>
struct sum_traits<int>
{
    typedef long sum_type;
};

template <>
struct sum_traits<float>
{
    typedef double sum_type;
};

template <>
struct sum_traits<double>
{
    typedef double sum_type;
};

template <typename Traits, typename T>
typename Traits::sum_type sum(T *first, T *last)
{
    typedef typename Traits::sum_type sum_type;
    sum_type total = sum_type();
    while (first != last)
    {
        total += *first;
        first++;
    }
    return total;
}

template <typename T>
typename sum_traits<T>::sum_type sum(T *first, T *last)
{
    return sum<sum_traits<T>, T>(first, last);
}

struct sum_char
{
    typedef char sum_type;
};

int main(int argc, char const *argv[])
{
    const size_t N = 3;
    char arr_char[N] = {'a', 'b', 'c'};

    cout << "sum(arr_char)           = " << sum(arr_char, arr_char + N) << endl;
    cout << "sum<sum_char>(arr_char) = " << sum<sum_char>(arr_char, arr_char + N) << endl;

    return 0;
}
