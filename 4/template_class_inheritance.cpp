template<typename T>
class TemplateClass
{
    public:
    T value1;
};

template<typename K>
class TemplateClass2 : TemplateClass<K>
{
    public:
    K value2;
};

template<typename T, typename K>
class TemplateClass3 : TemplateClass<T>
{
    public:
    K value2;
};

template<typename K>
class TemplateClass4 : TemplateClass<int>
{
    public:
    K value2;
};

class SimpleClass : TemplateClass<double>
{
    public:
    char value = 2;
};