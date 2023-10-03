#include <list>
#include <iostream>

int main(int argc, char** argv)
{
    //Создание
    {
        std::list<int> list1;             // пустой список
        std::list<int> list2(5);          // список list2 состоит из 5 чисел, каждый элемент имеет значение по умолчанию
        std::list<int> list3(5, 2);           // список list3 состоит из 5 чисел, каждое число равно 2
        std::list<int> list4{ 1, 2, 4, 5 };   // список list4 состоит из чисел 1, 2, 4, 5
        std::list<int> list5 = { 1, 2, 3, 5 }; // список list5 состоит из чисел 1, 2, 4, 5
        std::list<int> list6(list4);          // список list6 - копия списка list4
        std::list<int> list7 = list4;         // список list7 - копия списка list4
    }

    {
        std::list<int> numbers{ 1, 2, 3, 4, 5 };
  
        int first {numbers.front() };  // 1
        int last { numbers.back() };  // 5
    
        std::cout << "First: " << first << std::endl;
        std::cout << "Last: " << last << std::endl;
    
        // перебор в цикле
        for (int n : numbers)
            std::cout << n << "\t";
        std::cout << std::endl;
    
        // перебор с помощью итераторов
        for (auto iter = numbers.begin(); iter != numbers.end(); iter++)
        {
            std::cout << *iter << "\t";
        }
        std::cout << std::endl;
    }

    //Размер
    {
        {
            std::list<int> numbers{ 1, 2, 3, 4, 5 };
            int size = numbers.size();   // 5
        }

        {
            std::list<int> numbers{ 1, 2, 3, 4, 5 };
            bool is_empty = numbers.empty();
        }

        {
            std::list<int> numbers{ 1, 2, 3, 4, 5, 6 };
        numbers.resize(4);  // оставляем первые четыре элемента - numbers = {1, 2, 3, 4}
        numbers.resize(6, 8);    // numbers = {1, 2, 3, 4, 8, 8}
        }
    }

    //Изменение элементов
    {
        {
            std::list<int> numbers { 1, 2, 3, 4, 5 };
            numbers.assign({ 21, 22, 23, 24, 25 }); // numbers = { 21, 22, 23, 24, 25 }
            numbers.assign(4, 3);       // numbers = {3, 3, 3, 3}
            std::list<int> values { 6, 7, 8, 9, 10, 11 };
            auto start = ++values.begin();  // итератор указывает на второй элемент из values
            auto end = values.end();
            numbers.assign(start, end); //  numbers = { 7, 8, 9, 10, 11 }
        }

        {
            std::list<int> list1{ 1, 2, 3, 4, 5 };
            std::list<int> list2{ 6, 7, 8, 9};
            list1.swap(list2);
            // list1 = { 6, 7, 8, 9};
            // list2 = { 1, 2, 3, 4, 5 };
        }
    }

    //Добавление
    {
        std::list<int> numbers{ 1, 2, 3, 4, 5 };
        numbers.push_back(23);  // { 1, 2, 3, 4, 5, 23 }
        numbers.push_front(15); // { 15, 1, 2, 3, 4, 5, 23 }
        numbers.emplace_back(24);   // { 15, 1, 2, 3, 4, 5, 23, 24 }
        numbers.emplace_front(14);  // { 14, 15, 1, 2, 3, 4, 5, 23, 24 }

        std::list<int> numbers1{ 1, 2, 3, 4, 5 };
        auto iter1 = numbers1.cbegin(); // итератор указывает на первый элемент
        numbers1.insert(iter1, 0); // добавляем начало списка  
        //numbers1 = { 0, 1, 2, 3, 4, 5};
        
        std::list<int> numbers2{ 1, 2, 3, 4, 5 };
        auto iter2 = numbers2.cbegin(); // итератор указывает на первый элемент
        numbers2.insert(++iter2, 3, 4); // добавляем после первого элемента три четверки  
        //numbers2 = { 1, 4, 4, 4, 2, 3, 4, 5};
        
        std::list<int> values { 10, 20, 30, 40, 50 };
        std::list<int> numbers3{ 1, 2, 3, 4, 5 };
        auto iter3 = numbers3.cbegin(); // итератор указывает на первый элемент
        // добавляем в начало все элементы из values
        numbers3.insert(iter3, values.begin(), values.end());
        //numbers3 = { 10, 20, 30, 40, 50, 1, 2, 3, 4, 5};
        
        std::list<int> numbers4{ 1, 2, 3, 4, 5 };
        auto iter4 = numbers4.cend();   // итератор указывает на позицию за последним элементом
        // добавляем в конец список из трех элементов
        numbers4.insert(iter4, { 21, 22, 23 });
        //numbers4 = { 1, 2, 3, 4, 5, 21, 22, 23};
    }

    //Удаление
    {
        std::list<int> numbers { 1, 2, 3, 4, 5 };
        numbers.pop_front();    // numbers = { 2, 3, 4, 5 }
        numbers.pop_back();     // numbers = { 2, 3, 4 }
        numbers.clear();    // numbers ={}
        
        numbers = { 1, 2, 3, 4, 5 };
        auto iter = numbers.cbegin(); // указатель на первый элемент
        numbers.erase(iter);    // удаляем первый элемент
        // numbers = { 2, 3, 4, 5 }
        
        numbers = { 1, 2, 3, 4, 5 };
        auto begin = numbers.begin(); // указатель на первый элемент
        auto end = numbers.end();       // указатель на последний элемент
        numbers.erase(++begin, --end);  // удаляем со второго элемента до последнего
        //numbers = {1, 5}
    }


    return 0;
}