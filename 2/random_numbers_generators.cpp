#include <iostream>
#include <random>

/*
 *  Подробнее посмотреть какими объектами можно генерировать псевдослучайные объекты
 *  можно тут https://en.cppreference.com/w/cpp/numeric/random
 */

 class CL{
    public:
    CL(int x)
    {
        y = x;
    }

    private:
    int y;
 };
 
int main()
{
    CL cl{5};
    std::random_device rd;  //сид
    std::mt19937 gen(rd()); //генератор
    std::uniform_int_distribution<> distrib(1, 6); //распределение
 
    for (int n = 0; n != 10; ++n)
    {
        std::cout << distrib(gen) << ' ';
    }
    std::cout << '\n';
}