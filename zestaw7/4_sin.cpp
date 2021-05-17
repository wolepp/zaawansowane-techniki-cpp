#include <iostream>
#include <cmath>

using namespace std;

template<size_t N> double pow(double x)
{
    return ((N % 2) ? x : 1) * pow<N/2>(x * x);
}

template<> double pow<1>(double x)
{
    return x;
}

template<> double pow<0>(double x)
{
    return 1.;
}

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

template<int N> double sin(double x)
{
    return sin<N-1>(x) + (N%2 ? 1 : -1) * pow<2 * N-1>(x) / factorial<2 * N-1>();
}

template<> double sin<0>(double x)
{
    return 0.;
}

int main(int argc, char const *argv[])
{
    const double value = M_PI_2;

    cout << "nth approximation of sin(pi/2)" << endl;
    printf("%2d | %1.20f\n", 1, sin<1>(value));
    printf("%2d | %1.20f\n", 2, sin<2>(value));
    printf("%2d | %1.20f\n", 3, sin<3>(value));
    printf("%2d | %1.20f\n", 4, sin<4>(value));
    printf("%2d | %1.20f\n", 5, sin<5>(value));
    printf("%2d | %1.20f\n", 6, sin<6>(value));
    printf("%2d | %1.20f\n", 7, sin<7>(value));
    printf("%2d | %1.20f\n", 8, sin<8>(value));

    return 0;
}
