#include <iostream>
#include <cstring>

using std::cout, std::endl;


template <typename T> // przeciążenie
T max(T *data, size_t n)
{
    T _max = data[0];
    for (size_t i = 0; i < n; i++)
    {
        if (data[i] > _max) {
            _max = data[i];
        }
    }
    return _max;
}

template<typename T> // przeciążenie
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template<typename T> // przeciążenie
T* max(T *a, T *b) {
    return ((*a) > (*b)) ? a : b;
}

template<> // specjalizacja pełna
char *max(char *a, char *b)
{
    return (std::strcmp(a, b) > 0) ? a : b;
}

template<> // specjalizacja pełna
const char * max(const char *a, const char *b)
{
    return (std::strcmp(a, b) > 0) ? a : b;
}

template<typename T> // przeciążenie
const T* max(T *a, const T *b)
{
    return (*a) > (*b) ? a : b;
}


int main(int argc, char const *argv[])
{
    int i = 5;
    int j = 8;
    int k = max(i, j);      // max(T a, T b)

    double t[] = {.23, .55, 6.23, -.26, 0.234};
    double x = max(t, 5);   // max(T *data, size_t n)

    int *l = max(&i, &j);   // max(T a, T b) - pasuje lepiej niż max(T *a, T *b)

    cout << "k = " << k << endl;
    cout << "max(t) = " << x << endl;
    cout << "l = " << *l << endl;
    cout << "l to j = " << (l == &j) << endl;

    // ================ char* i const char*

    // 2 razy char*
    char *a = new char[5];
    char *b = new char[4];
    std::strncpy(a, "asdf", 5);
    std::strncpy(b, "bvc", 4);
    cout << "max('" << a << "', '" << b << "') = " << max(a, b) << endl;

    // 2 razy const char*
    const char *c1 = "Ola ma kota";
    const char *c2 = "Ola ma psa";
    cout << "max('" << c1 << "', '" << c2 << "') = " << max(c1, c2) << endl;

    // char* i const char*
    cout << "max('" << a << "', '" << c2 << "') = " << max(a, c2) << endl;
    cout << "max('a', 'O') = " << max('a', 'O') << endl;

    return 0;
}
