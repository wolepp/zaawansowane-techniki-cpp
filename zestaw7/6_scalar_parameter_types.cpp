#include <iostream>

using namespace std;

template<size_t N, typename T> struct Dot
{
    static T dot(T *a, T *b)
    {
        return (*a) * (*b) + Dot<N-1, T>::dot(++a, ++b);
    }
};

template<typename T> struct Dot<1, T>
{
    static T dot(T *a, T *b)
    {
        return (*a) * (*b);
    }
};

template<size_t N, typename T> T dot(T *a, T *b)
{
    return Dot<N, T>::dot(a, b);
}

int main(int argc, char const *argv[])
{
    double x[] = {1, 2, 3};
    double y[] = {5, 6, 7};

    cout << "(1, 2, 3) o (5, 6, 7) = " << dot<3, double>(x, y) << endl;
    return 0;
}
