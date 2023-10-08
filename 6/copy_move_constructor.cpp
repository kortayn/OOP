#include <iostream>
#include <iterator>
#include <utility>
#include <vector>
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
    //Следует помечать конструкторы перемещения noexept, если они не могут генерировать исключения
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

    private:
    std::vector<int> vec;
    static const size_t size = 100000;
};

int main(int argc, char** argv)
{
    TestClass test_class1(1);

    std::chrono::time_point<std::chrono::high_resolution_clock> start_point, end_point;

    //Замер времени копирования
    start_point = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        TestClass test_class2(test_class1);
    }

    end_point = std::chrono::high_resolution_clock::now();

    long long start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point)
                        .time_since_epoch().count();
    long long end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point)
                        .time_since_epoch().count();

    std::cout << "Copy time = " << (end - start) << " microseconds" << std::endl;

    //Замер времени перемещения
    start_point = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < 1000; ++i)
    {
        TestClass test_class2(std::move(test_class1));
    }

    end_point = std::chrono::high_resolution_clock::now();

    start = std::chrono::time_point_cast<std::chrono::microseconds>(start_point)
                .time_since_epoch().count();
    end = std::chrono::time_point_cast<std::chrono::microseconds>(end_point)
                .time_since_epoch().count();

    std::cout << "Move time = " << (end - start) << " microseconds" << std::endl;
    return 0;
}