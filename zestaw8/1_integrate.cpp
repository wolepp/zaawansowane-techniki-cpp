#include <iostream>

#include <cmath>

template <typename F>
double integrate(F f, double min, double max, double ds)
{
    double integral = .0;
    for (double x = min; x < max; x += ds)
    {
        integral += f(x);
    }
    return integral * ds;
};

// Funktor 
class Sin
{
    double _a;

public:
    Sin(double a) : _a(a){};
    double operator()(double x) { return sin(_a * x); }
};

int main(int argc, char const *argv[])
{

    std::cout << ::integrate(sin, 0, 3.1415926, 0.01) << std::endl;

    std::cout << ::integrate(Sin(0), 0, 3.1415926, 0.01) << std::endl;
    std::cout << ::integrate(Sin(1), 0, 3.1415926, 0.01) << std::endl;
    std::cout << ::integrate(Sin(2), 0, 3.1415926, 0.01) << std::endl;
    return 0;
}
