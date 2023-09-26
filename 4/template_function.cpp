#include <iostream>

template<typename T> T add(T a, T b)
{
    return add<T>(a + b, b + a);
}

template<typename T, typename K> void print(T& arg1, K& arg2)
{
    std::cout << arg1 << std::endl;
    std::cout << arg2 << std::endl;
}

int main(int argc, char** argv)
{
    int c1 = add(1, 2); //тип параметра выводится
    double c2 = add<double>(1.1, 2.2); //явное указание типа параметра

    print(c1, c2); //тип параметра выводится
    print<int, double>(c1, c2); //явное указание типа параметра
    return 0;
}