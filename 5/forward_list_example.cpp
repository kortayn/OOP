#include <forward_list>
#include <list>
#include <iostream>

int main(int argc, char** argv)
{
    //Создание
    {
        std::forward_list<int> list1;                     // пустой список
        std::forward_list<int> list2(5);                  // list2 имеет 5 элементов, каждый из которых имеет значение по умолчанию
        std::forward_list<int> list3(5, 2);               // list3 состоит из 5 чисел, каждое число равно 2
        std::forward_list<int> list4{ 1, 2, 4, 5 };       // list4 состоит из чисел 1, 2, 4, 5
        std::forward_list<int> list5 = { 1, 2, 3, 4, 5 }; // list5 состоит из чисел 1, 2, 3, 4, 5
        std::forward_list<int> list6(list4);              // list6 - копия списка list4
        std::forward_list<int> list7 = list4;             // list7 - копия списка list4
        std::forward_list<int> list8({ 1, 2, 3, 4, 5, 6 }); // list8  состоит из чисел 1, 2, 3, 4, 5, 6
    }

    //Обращение к элементам
    {
        std::forward_list<int> numbers { 1, 2, 3, 4, 5 };
  
        int first {numbers.front()};    // 1
        std::cout << "First: " << first << std::endl;
    
        for (int n : numbers)
            std::cout << n << "\t";
        std::cout << std::endl;
    }

    //Работа с размером как с list

    //Изменение значений как в list

    //Добавление элементов
    {
        std::forward_list<int> numbers{ 7, 8 };
        numbers.push_front(6);  // добавляем в начало число 6
        // numbers =  { 6, 7, 8 }
    
        numbers.emplace_front(-3);  // добавляем в начало число -3
        // numbers =  { -3, 6, 7, 8 }
    
        auto iter = numbers.begin();
        iter = numbers.emplace_after(iter, -2); // добавляем после итератора число -2
        // numbers =  { -3, -2, 6, 7, 8 }
    
        iter = numbers.insert_after(iter, -1);
        // numbers =  { -3, -2, -1, 6, 7, 8 }
    
        iter = numbers.insert_after(iter, 3, 0);    // добавляем три нуля
        // numbers =  { -3, -2, -1, 0, 0, 0, 6, 7, 8 }
    
        std::list<int> values{ 1, 2, 3 };
        iter = numbers.insert_after(iter, values.begin(), values.end()); // добавляем все элементы из values
        // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 6, 7, 8 }
    
        numbers.insert_after(iter, { 4, 5 }); // добавляем список { 4, 5 }
        // numbers =  { -3, -2, -1, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8 }
    }

    //Удаление
    {
        std::forward_list<int> numbers{ 1, 2, 3, 4, 5, 6, 7};
 
        numbers.pop_front();
        // numbers = { 2, 3, 4, 5, 6, 7};
        
        auto iter = numbers.erase_after(numbers.begin());
        // numbers = { 2, 4, 5, 6, 7 };
        // iter указывает на элемент 4
        
        numbers.erase_after(iter, numbers.end());
        // numbers = { 2, 4 };
    }
    return 0;
}