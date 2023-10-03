#include <vcruntime.h>
#include <vector>
#include <stdexcept>

int main(int argc, char** argv)
{
    {
        std::vector<int> v1;              // пустой вектор
        std::vector<int> v2(v1);          // вектор v2 - копия вектора v1
        std::vector<int> v3 = v1;         // вектор v3 - копия вектора v1
        std::vector<int> v4(5);           // вектор v4 состоит из 5 чисел, каждое число равно 0
        std::vector<int> v5(5, 2);        // вектор v5 состоит из 5 чисел, каждое число равно 2
        std::vector<int> v6{1, 2, 4, 5};  // вектор v6 состоит из чисел 1, 2, 4, 5
        std::vector<int> v7 = {1, 2, 3, 5}; // вектор v7 состоит из чисел 1, 2, 4, 5
        
        std::vector<int> v8(5);       // вектор состоит из 5 чисел, каждое число в векторе равно 0
        std::vector<int> v9{5};       // вектор состоит из одного числа, которое равно 5
        std::vector<int> v10(5, 2);    // вектор состоит из 5 чисел, каждое число равно 2
        std::vector<int> v11{5, 2};    // вектор состоит из двух чисел 5 и 2

        int first = v7.front();    // 1
        int last = v7.back();      // 5
        int second = v7[1];        // 2
    
        v7[0] = 6;  // изменяем значение   

        try
        {
            int n = v7.at(8);
        }
        catch (std::out_of_range e)
        {
        }

        //Добавление в конец вектора
        v7.push_back(5);
        v7.push_back(3);
        v7.push_back(10);

        //Или
        v7.emplace_back(5);
        v7.emplace_back(3);
        v7.emplace_back(10);

        //Сравнение векторов - поддерживаются все операторы сравнения
        bool is_vectors_equals = v1 == v2;
    }
    
    //Вставка элементов
    {
        std::vector<int> numbers{ 1, 2, 3, 4, 5 };
        auto iter = numbers.cbegin();   // константный итератор указывает на первый элемент
        numbers.emplace(iter + 2, 8); // добавляем после второго элемента  numbers = { 1, 2, 8, 3, 4, 5};

        std::vector<int> numbers1{ 1, 2, 3, 4, 5 };
        auto iter1 = numbers1.cbegin(); // константный итератор указывает на первый элемент
        numbers1.insert(iter1 + 2, 8); // добавляем после второго элемента  
        //numbers1 = { 1, 2, 8, 3, 4, 5};
        
        std::vector<int> numbers2 { 1, 2, 3, 4, 5 };
        auto iter2 = numbers2.cbegin(); // константный итератор указывает на первый элемент
        numbers2.insert(iter2 + 1, 3, 4); // добавляем после первого элемента три четверки  
        //numbers2 = { 1, 4, 4, 4, 2, 3, 4, 5};
        
        std::vector<int> values { 10, 20, 30, 40, 50 };
        std::vector<int> numbers3 { 1, 2, 3, 4, 5 };
        auto iter3 = numbers3.cbegin(); // константный итератор указывает на первый элемент
        // добавляем после первого элемента три первых элемента из вектора values
        numbers3.insert(iter3 + 1, values.begin(), values.begin() + 3);
        //numbers3 = { 1, 10, 20, 30, 2, 3, 4, 5};
        
        std::vector<int> numbers4 { 1, 2, 3, 4, 5 };
        auto iter4 = numbers4.cend();   // константный итератор указывает на позицию за последним элементом
        // добавляем в конец вектора numbers4 элементы из списка { 21, 22, 23 }
        numbers4.insert(iter4, { 21, 22, 23 });
        //numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};  
    }

    //Удаление элементов
    {
        //Удаление всех
        {
            std::vector<int> v { 1,2,3,4 };
            v.clear();
        }

        //Удаление последнего
        {
            std::vector<int> v { 1,2,3,4 };
            v.pop_back();       // v = { 1,2,3 }
        }

        {
            std::vector<int> numbers1 { 1, 2, 3, 4, 5, 6 };
            auto iter = numbers1.cbegin(); // указатель на первый элемент
            numbers1.erase(iter + 2);   // удаляем третий элемент
            // numbers1 = { 1, 2, 4, 5, 6 }
            
            std::vector<int> numbers2 = { 1, 2, 3, 4, 5, 6 };
            auto begin = numbers2.cbegin(); // указатель на первый элемент
            auto end = numbers2.cend();     // указатель на последний элемент
            numbers2.erase(begin + 2, end - 1); // удаляем с третьего элемента до последнего
            // numbers2 = {1, 2, 6}
        }

        //std::erase в c++20
        {
            std::vector<int> numbers3 { 1, 2, 3, 1, 5, 6 };
            std::erase(numbers3, 1); // numbers3 = { 2, 3, 4, 5, 6 }
        }
    }

    //Размер
    {
        std::vector<int> numbers{1, 2, 3};
        bool is_empty = numbers.empty();
        size_t size = numbers.size();

        //Изменение
        std::vector<int> numbers1 { 1, 2, 3, 4, 5, 6 };
        numbers1.resize(4); // оставляем первые четыре элемента - numbers1 = {1, 2, 3, 4}
        numbers1.resize(6, 8);   // numbers1 = {1, 2, 3, 4, 8, 8}
    }

    //Изменение элементов
    {
        {
            std::vector<std::string> langs = { "Java", "JavaScript", "C"};
            langs.assign(4, "C++"); // langs = {"C++", "C++", "C++", "C++"}
        }

        {
            std::vector<std::string> langs{ "Java", "JavaScript", "C"};
            langs.assign({ "C++", "C#", "C"}); // langs = { "C++", "C#", "C"}
        }

        //Обмен
        {
            std::vector<std::string> clangs { "C++", "C#", "Java" };
            std::vector<std::string> ilangs { "JavaScript", "Python", "PHP"};
            clangs.swap(ilangs);    // clangs = { "JavaScript", "Python", "PHP"};
        }
    }


    return 0;
}