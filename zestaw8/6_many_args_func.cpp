#include <iostream>

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

template <typename F>
double integrate(F f, std::pair<double, double> min, std::pair<double, double> max, double ds)
{
    double integral = .0;
    for (double x = min.first; x < max.first; x += ds)
    {
        for (double y = min.second; y < max.second; y += ds)
        {
            integral += f(x, y);
        }
    }
    // dwukrotnie razy ds
    return integral * ds * ds;
};

class First
{
public:
    double operator()(double x)
    {
        return x;
    }
    double operator()(double x, double)
    {
        return x;
    }
};

class Second
{
public:
    double operator()(double, double y)
    {
        return y;
    }
};

class Constant
{
    double _c;

public:
    Constant(double c) : _c(c){};
    double operator()(double) { return _c; }
    double operator()(double, double) { return _c; }
};

template <typename LHS, typename RHS>
class AddExpr
{
    LHS _lhs;
    RHS _rhs;

public:
    AddExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r){};
    double operator()(double x)
    {
        return _lhs(x) + _rhs(x);
    }
    double operator()(double x, double y)
    {
        return _lhs(x, y) + _rhs(x, y);
    }
};

template <typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS &l, const RHS &r)
{
    return AddExpr<LHS, RHS>(l, r);
};

template <typename LHS>
AddExpr<LHS, Constant> operator+(const LHS &l, double r)
{
    return AddExpr<LHS, Constant>(l, Constant(r));
};

template <typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS &r)
{
    return AddExpr<Constant, RHS>(Constant(l), r);
};

int main(int argc, char const *argv[])
{
    First x;
    Second y;

    std::cout << integrate(x, 0, 1, 0.0001)  << std::endl;
    std::cout << integrate(x + y, std::make_pair(0, 0), std::make_pair(1, 1), 0.0001)  << std::endl;
    return 0;
}
