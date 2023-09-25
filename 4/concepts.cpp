#include <iostream>
template<typename T>
concept C = requires(T item)
{
    item < item; item == item;
};

class CL{};

template<C T>
bool my_equal(T a, T b)
{
    return a == b;
}

int main(int argc, char** argv)
{
    std::cout << std::boolalpha << C<int> << std::endl;
    std::cout << std::boolalpha << C<double> << std::endl;
    std::cout << std::boolalpha << C<CL> << std::endl;

    std:: cout << my_equal<int>(1, 2) << std::endl;
    CL a1;
    CL a2;
    std:: cout << my_equal<CL>(a1, a2) << std::endl; //Из-за этой строки не скомпилируется - CL не удовлетворяет концепту

    return 0;
}