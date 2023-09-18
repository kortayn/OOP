#include "class_with_separate_definition.h"

ClassWithSeparateDefinition::ClassWithSeparateDefinition()
{
    int_value = 10;
    string_value = "Hello_World";
}

ClassWithSeparateDefinition
::ClassWithSeparateDefinition(std::string str, int i)
{
    string_value = str;
    int_value = i;
}

std::string ClassWithSeparateDefinition::method1()
{
    return string_value;
}

int ClassWithSeparateDefinition::method2()
{
    return int_value;
}