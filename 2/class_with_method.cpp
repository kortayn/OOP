class ClassWithMethod
{
public:
    int get_value1()
    {
        return value1;
    }

    float get_value2()
    {
        return value2;
    }

    void set_value1(int value)
    {
        if(value > 100)
        {
            value1 = value;
        }
        
    }

    void set_value2(float value)
    {
        value2 = value;
    }

private:
    int value1;
    float value2;
};

int main(int argc, char** argv)
{
    ClassWithMethod object_with_method;
    object_with_method.set_value1(10);

    ClassWithMethod *object_ptr_with_method = new ClassWithMethod();
    object_ptr_with_method->set_value2(10.4);
    return 0;
}