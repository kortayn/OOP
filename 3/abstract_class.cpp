#include <iostream>
#include <ostream>
#include <string>

class AbstractClass
{
    public:
    virtual void print() = 0;
};

class ConcreteClassA : public AbstractClass
{
    public:
    ConcreteClassA(int value)
    {
        this->value = value;
    }

    void print() override
    {
        std::cout << value << std::endl;
    }

    private:
    int value;
};

class ConcreteClassB : public AbstractClass
{
    public:
    ConcreteClassB(std::string str, double d)
    {
        value1 = str;
        value2 = d;
    }

    void print() override
    {
        std::cout << value1 << " " << value2 << std::endl;
    }

    private:
    std::string value1;
    double value2;
};

int main(int argc, char** argv)
{
    AbstractClass *cc = new ConcreteClassA(10);
    cc->print();

    AbstractClass *cc2 = new ConcreteClassB("string", 10.5);
    cc2->print();
    return 0;
}