#include <vector>

int main(int argc, char** argv)
{
    std::vector<int> numbers{ 1,2,3,4 };
    std::vector<int>::iterator iter = numbers.begin();  // получаем итератор

    //cbegin(), cend() - получение константных итераторов
    //rbegin(), rend() - получение реверсивных итераторов
    // получаем элемент, на который указывает итератор
    int elem =  *iter;    // 1
    // изменяем элемент
    *iter = 125;

    // переходим на 1 элемент вперед ко 2-му элементу
    ++iter;
 
    // переходим на 2 элемента вперед к 4-му элементу
    iter +=2; 
 
    // переходим назад на 3 элемента к 1-му элементу
    iter = iter - 3;

    for(auto start{numbers.begin()}; start !=numbers.end(); start++ )
    {
        //Do something
    }
    return 0;
}