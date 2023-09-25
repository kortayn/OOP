#include <exception>
#include <sstream>
#include <iostream>

class FirstItemLessOrEqual : std::exception
{
    private:
    int log_a;
    int log_b;
    public:
    FirstItemLessOrEqual(int a, int b) : std::exception()
    {
        a = log_a;
        b = log_b;
    }
    const char* what() const noexcept override
    {
        return "a less or equal b";
    }
};

int sub_natural(int a, int b)
{
    if (a <= b) {
        FirstItemLessOrEqual filoe(a, b);
        throw filoe;
    }

    return a - b;
}


int main(int argc, char** argv)
{
    int result;
    try
    {
        result = sub_natural(1, 2);
    }
    catch (const FirstItemLessOrEqual f)
    {
        std::cout << f.what() << std::endl;
    }
    return 0;
}