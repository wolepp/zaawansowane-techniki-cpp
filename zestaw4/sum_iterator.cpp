#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
struct sum_traits;

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
    typedef long sum_type;
    static sum_type zero()
    {
        return 0;
    }
};

template <typename IT>
typename sum_traits<typename std::iterator_traits<IT>::value_type>::sum_type sum(IT first, IT end)
{
    typedef typename std::iterator_traits<IT>::value_type value_type;
    typedef typename sum_traits<value_type>::sum_type sum_type;
    sum_type total = sum_traits<value_type>::zero();
    while (first != end)
    {
        total += *first;
        first++;
    }
    return total;
}

int main(int argc, char const *argv[])
{
    const size_t N = 3;
    char arr[N] = {'a', 'b', 'c'};
    std::vector vec = {'a', 'b', 'c'};
    std::vector vec_int = {1, 2, 3, 4, 5};

    std::cout << "sum(arr) = " << sum(arr, arr + N) << std::endl;
    std::cout << "sum(vec) = " << sum(vec.begin(), vec.end()) << std::endl;
    std::cout << "sum(vec_int) = " << sum(vec_int.begin(), vec_int.end()) << std::endl;

    return 0;
}
