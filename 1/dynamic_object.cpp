#include <iostream>

int main(int argc, char** argv)
{
    //создание
    int *ptr1{new int};
    
    int *ptr2 = new int;

    //инициализация
    int *ptr3{new int()}; //0
    int *ptr4{new int{}}; //0
    int *ptr5{new int{5}}; //5

    int *ptr6 = ptr5;
    *ptr6 = 3;
    
    //удаление объекта
    int *ptr7 = new int(5);
    delete ptr7;
    //delete ptr7;//Что будет тут?
    ptr7 = nullptr; //обязательно обнуляем указатель после удаления
    //delete ptr7; //Что будет тут?
     
    ptr7 = new int(15); //так можно сделать?
    return 0;
}