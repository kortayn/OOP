#include <vector>
#include <iostream>
#include <chrono>

class TestClass
{
    public:
    
    //Простой конструктор
    TestClass(int m)
    {
        for(int i = 0; i < size; ++i)
        {
            vec.push_back(i * m);
        }
    }

    //Конструктор копирования
    TestClass(TestClass& test_class)
    {
        vec = test_class.vec;
    }

    //Конструктор перемещения
    TestClass(TestClass&& test_class) noexcept
    {
        vec = std::move(test_class.vec);
    }

    std::vector<int>::iterator begin()
    {
        return vec.begin();
    }

    std::vector<int>::iterator end()
    {
        return vec.end();
    }

    //При присваивании используется подход move and swap
    TestClass& operator=(TestClass&& object)
    {
        if (&object != this) 
        {
            //Перемещаем данные во временный объект
            TestClass temp_object(std::move(object));
            //Если при перемещении произойдёт ошибка - текущий объект сохранит своё состояние
            
            throw std::string("Exception!!!");

            //Если создание копии произошло успешно, можно переместить данные в конечную точку
            std::swap(this->vec, temp_object.vec);
        }

        return *this;
    }

    private:
    std::vector<int> vec;
    static const size_t size = 20;
};


int main(int argc, char** argv)
{
    TestClass test_class1(1);
    TestClass test_class2(2);

    for(int val : test_class1)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    try
    {
        test_class1 = std::move(test_class2);
    }
    catch(std::string ex)
    {
        std::cout << "Throw exception" << std::endl;
    }

    for(int val : test_class1)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
    
    return 0;
}