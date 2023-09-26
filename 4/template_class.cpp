#include <string>

template<typename T, typename K = int>
class TemplateClass
{
    public:
    T value1;
    K value2;
};

int main(int argc, char** argv)
{
    TemplateClass<int, std::string> tc;
    return 0;
}