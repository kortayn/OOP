template<typename T>
class TemplateClass
{
    public:
    T value1;
};

template<typename K>
class TemplateClass2 : public TemplateClass<K>
{
    public:
    K value2;
};

template<typename T, typename K>
class TemplateClass3 : public TemplateClass<T>
{
    public:
    K value2;
};

template<typename K>
class TemplateClass4 : public TemplateClass<int>
{
    public:
    K value2;
};

class SimpleClass : public TemplateClass<double>
{
    public:
    char value = 2;
};