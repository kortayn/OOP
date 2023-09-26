#include <iostream>

template<typename T, typename K>
class TemplateClass
{
    public:
    T value1;
    K value2;
};

template<>
class TemplateClass<int, char>
{
    public:
    int method()
    {
        return 1 + 2;
    }
};

template<typename K>
class TemplateClass<K, char>
{
    public:
    void m()
    {
        std::cout << "Do something" << std::endl;
    }
};

int main (int argc, char** argv)
{
    TemplateClass<int, double> tc;
    TemplateClass<int, char> tc2; //будет использоваться полная специализация
    tc2.method();
    TemplateClass<double, char> tc3; //будет использоваться частичная специализация
    return 0;
}