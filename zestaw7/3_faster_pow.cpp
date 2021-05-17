#include <iostream>

using namespace std;

template<size_t N> double pow(double x)
{
    return ((N % 2) ? x : 1) * pow<N / 2>(x * x);
}

template<> double pow<1>(double x)
{
    return x;
}

template<> double pow<0>(double x)
{
    return 1.;
}

template<int K, int N> struct Pow
{
    enum {val = K * Pow<K, N-1>::val};
};

template<int K> struct Pow<K, 0>
{
    enum {val = 1};
};

int main(int argc, char const *argv[])
{
    srandom(42);
    const long N = 100000000;

    // time of slow pow
    clock_t startSlow = clock();
    for (long i = 0; i < N; i++)
    {
        Pow<5, 10>::val;
    }
    clock_t stopSlow = clock();

    // time of recurent quick pow
    clock_t startQuick = clock();
    for (long i = 0; i < N; i++)
    {
        pow<5>(10);
    }
    clock_t stopQuick = clock();

    std::cout << "Time of slow pow: " << (stopSlow - startSlow) / (double) CLOCKS_PER_SEC << "s" << std::endl;
    std::cout << "Time of quick pow: " << (stopQuick - startQuick) / (double) CLOCKS_PER_SEC << "s"  << std::endl;

    std::cout << "10th power of 5 = " << pow<5>(10) << std::endl;
    return 0;
}
