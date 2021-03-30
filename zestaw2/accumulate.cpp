#include <iostream>
#include <vector>
#include <list>
#include <complex>

using namespace std;

template <typename InputIterator, class T>
T accumulate(InputIterator begin, InputIterator end, T init)
{
    T sum = init;
    for (; begin != end; begin++)
    {
        sum += *begin;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    list<double> lista;
    lista.push_back(1.);
    lista.push_back(.2);
    lista.push_back(2.3);

    cout << *lista.begin();
    for (auto it = ++lista.begin(); it != lista.end(); it++)
    {
        cout << " + " << *it;
    }
    cout << " = " << accumulate(lista.begin(), lista.end(), 0.) << endl;

    vector<complex<double>> wektor;
    wektor.push_back(1. + 2i);
    wektor.push_back(2.4 + 6.2i);
    wektor.push_back(4.2 - 4i);

    cout << *wektor.begin();
    for (auto it = ++wektor.begin(); it != wektor.end(); it++)
    {
        cout << " + " << *it;
    }
    cout << " = " << accumulate(wektor.begin(), wektor.end(), 0. + 0i) << endl;

    return 0;
}
