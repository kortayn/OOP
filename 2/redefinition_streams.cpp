#include <iostream>
#include <ostream>

class MyClass
{
public:
    MyClass()
    {
        str_value = "Int value is ";
        int_value = 10;
    }

    friend std::ostream& operator<< (std::ostream &os, const MyClass my_class)
    {
        return os << my_class.str_value << my_class.int_value;
    }

private:
    std::string str_value;
    int int_value;
};



int main(int argc, char** argv)
{
    MyClass mc;
    std::cout << mc << std::endl;
    return 0;
}