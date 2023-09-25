#include <iostream>
#include <string>

class A
{
    public:

    A(std::string str1, std::string str2)
    {
        value1 = str1;
        value2 = str2;
    }

    std::string to_string()
    {
        return value1 + " " + value2;
    }

    private: //унаследуется, но внутри наследника видно не будет
    std::string value1;
    std::string value2;
};

class B : public A
{
    public:

    B(std::string str1, std::string str2, std::string str3) : A(str1, str2)
    {
        value3 = str3;
    }

    std::string to_string()
    {
        return A::to_string() + " " + value3;
    }

    private:
    std::string value3;
};

int main(int argc, char** argv)
{
    A *a1 = new A("q", "w");
    std::cout << a1->to_string() << std::endl;

    B *b1 = new B("a", "b", "c");
    std::cout << b1->to_string() << std::endl;

    A *a2 = new B("z", "x", "c");
    std::cout << a2->to_string() << std::endl;
}