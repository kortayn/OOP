#include <memory> //тут определён unique_ptr
//unique_ptr применяется для создания уникальных указателей

int main(int argc, char** argv)
{
    std::unique_ptr<int> ptr; // ptr = nullptr
    // аналогично
    std::unique_ptr<int> ptr2{};
    std::unique_ptr<int> ptr3{nullptr};

    //Выделение памяти и создание объекта
    //c++14 и позже
    std::unique_ptr<int> ptr4 { std::make_unique<int>(125) };

    //До с++14
    //std::unique_ptr<int> ptr5 { new int(125) };
    //Удаление объекта
    ptr4.reset(); //аналогично reset(ptr4)
    //Удаление старого объекта и создание нового
    
    ptr4.reset(new int(100));

    //Получение обычного указателя
    std::unique_ptr<int> ptr6 { std::make_unique<int>(125) };
    int* pointer = ptr6.get();
    *pointer = 10;
    //ptr6

    //Работа с массивами
    std::unique_ptr<int[]> int_array = { std::make_unique<int[]>(10) };
    int_array[5] = 10;
    
    return 0;
}