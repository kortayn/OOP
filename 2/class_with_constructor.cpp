#include <memory>
class ClassWithConstructor
{
public:
    ClassWithConstructor()
    {
        int_value = 10;
        float_value = 5.5;
    }

    ClassWithConstructor(int int_value, float float_value)
    {
        this->int_value = int_value;
        this->float_value = float_value;
    }

private:
    int int_value;
    float float_value;
};

int main(int argc, char** argv)
{
    ClassWithConstructor object1;
    ClassWithConstructor object2(1, 2.2);

    ClassWithConstructor *object_ptr1 = new ClassWithConstructor();
    ClassWithConstructor *object_ptr2 = new ClassWithConstructor(1, 2.2);

    std::unique_ptr<ClassWithConstructor> unique_ptr_class_with_constructor1 {std::make_unique<ClassWithConstructor>()};
    std::unique_ptr<ClassWithConstructor> unique_ptr_class_with_constructor2 {std::make_unique<ClassWithConstructor>(1, 2.2)};

    delete object_ptr1;
    delete object_ptr2;

    return 0;
}