#ifndef CLASS_WITH_SEPARATE_DEFINITION

#include <string>

class ClassWithSeparateDefinition
{
public:
    ClassWithSeparateDefinition();
    ClassWithSeparateDefinition(std::string, int);

    std::string method1();
    int method2();
private:
    int int_value;
    std::string string_value;
};

#endif