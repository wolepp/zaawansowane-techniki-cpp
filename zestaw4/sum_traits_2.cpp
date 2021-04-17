#include <iostream>

using namespace std;

template <typename T>
struct sum_traits
{
    typedef T sum_type;
    static sum_type zero()
    {
        return T();
    }
};

template <>
struct sum_traits<char>
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

template <>
struct sum_traits<int>
{
    typedef int sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

template <>
struct sum_traits<float>
{
    typedef double sum_type;
    static sum_type zero()
    {
        return 0.0;
    }
};

template <>
struct sum_traits<double>
{
    typedef double sum_type;
    static sum_type zero()
    {
        return 0.0;
    }
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *first, T *last)
{
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (first != last)
    {
        total += *first;
        first++;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    const size_t N = 5;
    int arr_int[N] = {1, 2, 3, 4, 5};
    char arr_char[N] = {'a', 'b', 'c', 'd', 'e'};

    cout << "sum(arr_int) = " << sum(arr_int, arr_int + N) << endl;
    cout << "sum(arr_char) = " << sum(arr_char, arr_char + N) << endl;

    return 0;
}
