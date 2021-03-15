#include <iostream>

using std::cout, std::endl;

// zadanie 1 --------------------------------------------------
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

// zadanie 2 --------------------------------------------------
template <typename T, typename U>
T convert(U u)
{
    return (T)u;
}

// zadanie 3 --------------------------------------------------
template <size_t N, typename T>
T dot_product(T *a, T *b)
{
    T total = 0.0;
    for (size_t i = 0; i < N; i++)
    {
        total += a[i] * b[i];
    }
    return total;
}

// zadanie 4 --------------------------------------------------
template <template <int N> class C, int K>
void print(C<K> c)
{
    for (int i = 0; i < K; i++)
    {
        std::cout << c.data[i] << std::endl;
    }
}

template <int N>
struct IntList
{
    int data[N];
};

// zadanie 5 --------------------------------------------------
template <typename T, size_t N = 100>
class Stack
{
private:
    T _rep[N];
    size_t _top;

public:
    typedef T value_type;
    Stack() : _top(0){};

    void push(T val) { _rep[_top++] = val; }
    T pop() { return _rep[--_top]; };
    bool is_empty() { return (_top == 0); }
};

template<typename S> S::value_type sum(S s) {
    typename S::value_type total;
    while (!s.is_empty())
    {
        total += s.pop();
    }
    return total;
}

// main ======================================================================
int main(int argc, char const *argv[])
{
    // Zadanie 1
    cout << "---- Zadanie 1" << endl;
    cout << max<int>(4, 8) << endl;
    cout << max<float>(3.23, 3.22) << endl;
    cout << max<std::string>("Andrzej", "Zygmunt") << endl;

    // Zadanie 2
    cout << "---- Zadanie 2" << endl;
    char converted_int = convert<char>(70);
    cout << converted_int << endl;

    // Zadanie 3
    cout << "---- Zadanie 3" << endl;
    double x[4] = {1, 2, 3, 4};
    double y[4] = {5, 6, 7, 8};
    double dot_product_result = dot_product<4>(x, y);
    cout << dot_product_result << endl;

    // Zadanie 4
    cout << "---- Zadanie 4" << endl;
    IntList<5> list = {{1, 2, 3, 4, 5}};
    print(list);

    // Zadanie 5
    cout << "---- Zadanie 5" << endl;
    Stack<double, 10> stack;
    for (int i = 0; i < 10; i++)
    {
        stack.push(i);
    }
    cout << "sum [1, 10] = " << sum(stack) << endl;
    
    return 0;
}
