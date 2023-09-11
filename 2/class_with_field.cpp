#include <string>

class ClassWithFields
{
    public:
    int value1;
    float value2;
    std::string str;
};

int main(int argc, char** argv)
{
    ClassWithFields object_with_fields;
    object_with_fields.value1 = 1;
    object_with_fields.value2 = 2.1;
    object_with_fields.str = "Hello!";

    ClassWithFields *object_ptr_with_fields = new ClassWithFields();
    (*object_ptr_with_fields).str = "Hello";
    object_ptr_with_fields->value1 = 10;

    return 0;
}