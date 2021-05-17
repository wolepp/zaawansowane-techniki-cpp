#include <iostream>

using namespace std;

template<size_t N> double dot(double *x, double *y)
{
    return (*x) * (*y) + dot<N-1>(++x, ++y);
}

template<> double dot<1>(double *x, double *y)
{
    return (*x) * (*y);
}

int main(int argc, char const *argv[])
{
    double x[] = {1, 2, 3};
    double y[] = {5, 6, 7};

    cout << "(1, 2, 3) o (5, 6, 7) = " << dot<3>(x, y) << endl;
    return 0;
}
