namespace my_namespace
{
    int function_into_user_namespace(int x)
    {
        return x;
    }
}

double function_into_global_namespace(double y)
{
    return y;
}

int main(int argc, char** argv)
{
    //Доступ к объекту, находящемуся внутри локального пространства имён
    my_namespace::function_into_user_namespace(10);

    //Задание псевдонима для пространства имён
    namespace mn = my_namespace;
    mn::function_into_user_namespace(1);
    //Включение пространства имён в глобальное пространство имён
    using namespace my_namespace;
    function_into_user_namespace(55);
    
    //Доступ к объекту, находящемуся внутри глобального пространства имён
    function_into_global_namespace(5.5);

    //Или
    ::function_into_global_namespace(4.4);

    return 0;
    
}