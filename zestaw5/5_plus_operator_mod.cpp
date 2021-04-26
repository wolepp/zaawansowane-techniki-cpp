#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

template <bool flag, typename T1, typename T2>
struct If_then_else
{
    typedef T1 Result;
};

template <typename T1, typename T2>
struct If_then_else<false, T1, T2>
{
    typedef T2 Result;
};

template <typename T1, typename T2>
struct Promote
{
    typedef typename If_then_else<(sizeof(T1) > sizeof(T2)),
                                  T1,
                                  typename If_then_else<(sizeof(T1) < sizeof(T2)),
                                                        T2,
                                                        void>::Result>::Result Result;
};

template <typename T>
struct Promote<T, T>
{
    typedef T Result;
};

#define MK_PROMOTION(T1, T2, Tr) \
    template <>                  \
    class Promote<T1, T2>        \
    {                            \
    public:                      \
        typedef Tr ResultT;      \
    };                           \
                                 \
    template <>                  \
    class Promote<T2, T1>        \
    {                            \
    public:                      \
        typedef Tr ResultT;      \
    };

MK_PROMOTION(bool, char, int)
MK_PROMOTION(bool, unsigned char, int)
MK_PROMOTION(bool, signed char, int)

template <typename T>
std::vector<T>
operator+(const std::vector<T> &a,
          const std::vector<T> &b)
{
    assert(a.size() == b.size());

    std::vector<T> res(a);
    for (size_t i = 0; i < a.size(); ++i)
        res[i] += b[i];

    return res;
}

template <typename T, typename U>
std::vector<typename Promote<T, U>::Result>
operator+(const std::vector<T> &a,
          const std::vector<U> &b)
{
    assert(a.size() == b.size());

    std::vector<typename Promote<T, U>::Result> res(a.size());
    for (size_t i = 0; i < a.size(); ++i)
        res[i] = a[i] + b[i];

    return res;
}

int main(int argc, char const *argv[])
{
    std::vector<double> x(10);
    std::vector<double> y(10);
    std::vector<int>    l(10);

    x+y;
    l+x;

    return 0;
}
