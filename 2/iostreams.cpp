#include <iostream>
#include <string>
#include <system_error>

int main(int argc, char** argv)
{
    /*
    istream
    ostream
    iostream
    */

    //Запись в поток
    std::cout << 123 << std::endl;

    //чтение данных
    int x;
    std::cin >> x;
    std::cout << x << std::endl;

    //Чтение строки с пробелами
    std::string str;
    std::getline(std::cin, str);

    //Вывод ошибок
    std::cerr << "Error" << std::endl; 
    return 0;
}