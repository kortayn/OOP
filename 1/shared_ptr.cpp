#include <memory>
//shared_ptr позволяет создавать указатели на один и тот же объект

int main(int argc, char** argv){
    //Создание
    std::shared_ptr<int> ptr1;   // ptr1 = nullptr

    //Инициализация
    std::shared_ptr<int> ptr2{std::make_shared<int>(22)};

    //Изменение
    *ptr2 = 33;

    //Инициализация другим shared_ptr
    std::shared_ptr<int> ptr3 {std::make_shared<int>(22)};
    std::shared_ptr<int> ptr4 {ptr3};

    //Массивы со стандарта c++20
    std::shared_ptr<int[]> int_array2d {std::make_shared<int[]>(10)};

    //Обращение к элементам массива
    int_array2d[4] = 100;
    
    return 0;
}
