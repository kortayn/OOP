#include "factorial.h"

int factorial(int n)
{
    return n <= 1 ? n : n * factorial(n - 1);
}

int throw_method()
{
    throw std::string("Throw excaption!");
    return 0;
}