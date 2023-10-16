//RAII
class ClassWithDestructor
{
public:
    ClassWithDestructor()
    {
        array = new int[]{1,2,3,4,5};
    }

    ~ClassWithDestructor()
    {
        delete [] array;
    }
private:
    int *array;
};