#include <set>


//set - упорядоченное множество
//unordered_set - неупорядоченное множество, поддерживает те же операции
int main(int argc, char** argv)
{
    //Создание
    {
        {
            std::set<int> numbers;
        }
        {
            std::set<int> numbers {1, 2, 3, 4, 5};
        }
    }

    //Размер
    {
        std::set<int> numbers{1, 2, 3};
        bool is_empty = numbers.empty();
        size_t size = numbers.size();
    }

    //Добавление
    {
        std::set<int> numbers{3, 4, 5};
 
        numbers.insert(1);
        numbers.insert(2);
        numbers.insert(2); //Не будет добавлено
        numbers.insert(2);
        numbers.insert(6);
    }

    //Удаление
    {
        std::set<int> numbers{2, 3, 4, 5};
 
        numbers.erase(1);
        numbers.erase(2);
        numbers.erase(3);
    }

    //Количество элементов и определение наличия элемента
    {
        std::set<int> numbers{2, 3, 4, 5};
        int count_ten = numbers.count(10);
        int count_two = numbers.count(2);

        //Появилось в c++20
        bool is_contain_two = numbers.contains(2);
    }
    return 0;
}