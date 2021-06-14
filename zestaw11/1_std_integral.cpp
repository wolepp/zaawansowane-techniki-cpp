#include <iostream>
#include <concepts>

template <std::integral T>
auto gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char const *argv[])
{
    std::cout << "gcd(246, 12) = " << gcd(246, 12) << std::endl;

    // std::cout << "gcd('a', 'b') = " << gcd('a', 'b') << std::endl;
    // std::cout << "gcd(true, false) = " << gcd(true, false) << std::endl;


    return 0;
}
