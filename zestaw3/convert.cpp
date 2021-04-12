#include <iostream>

using namespace std;

template<typename T, typename U>
T convert(U u)
{
    return static_cast<T>(u);
}

template<> // specjalizacja
int convert<int, double>(double u)
{
    cout << "Konwersja double na int" << endl;
    return static_cast<int>(u);
}

template<>
double convert<double, double>(double u)
{
    cout << "Konwersja double na double" << endl;
    return -u;
}


int main(int argc, char const *argv[])
{
    double to_convert = 3.1415;

    int x = convert<int>(to_convert);
    double u = convert<double>(to_convert);

    cout << to_convert << " po konwersji na:" << endl;
    cout << " - int: " << x << endl;
    cout << " - double: " << u << endl;

    return 0;
}
