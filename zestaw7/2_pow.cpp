#include <iostream>

using namespace std;

template<int K, int N> struct Pow
{
    enum {val = K * Pow<K, N-1>::val};
};

template<int K> struct Pow<K, 0>
{
    enum {val = 1};
};

int pow(int k, int n)
{
    if (n > 1)
    {
        return k * pow(k, n-1);
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    srandom(42);
    const long N = 100000000;

    // time of recurent function
    clock_t startFunc = clock();
    for (long i = 0; i < N; i++)
    {
        pow(5, 5);
    }
    clock_t stopFunc = clock();

    // time of recurent function template
    clock_t startTemplate = clock();
    for (long i = 0; i < N; i++)
    {
        Pow<5, 5>::val;
    }
    clock_t stopTemplate = clock();

    std::cout << "Time of function: " << (stopFunc - startFunc) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Time of template function: " << (stopTemplate - startTemplate) / (double) CLOCKS_PER_SEC << "s"  << std::endl;

    std::cout << "5th power of 5 = " << pow(5, 5) << std::endl;
    return 0;
}
