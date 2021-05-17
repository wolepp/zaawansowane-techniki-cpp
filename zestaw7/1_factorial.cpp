#include <iostream>

using std::cout, std::endl;

template <int N>
int factorial()
{
    return N * factorial<N - 1>();
}

template <>
int factorial<1>()
{
    return 1;
}

int factorial(int N)
{
    if (N > 1) {
        return N * factorial(N - 1);
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
        factorial(10);
    }
    clock_t stopFunc = clock();

    // time of recurent function template
    clock_t startTemplate = clock();
    for (long i = 0; i < N; i++)
    {
        factorial<10>();
    }
    clock_t stopTemplate = clock();

    std::cout << "Time of function: " << (stopFunc - startFunc) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Time of template function: " << (stopTemplate - startTemplate) / (double) CLOCKS_PER_SEC << "s"  << std::endl;

    std::cout << "factorial of 6 = " << factorial<6>() << std::endl;
    return 0;
}
