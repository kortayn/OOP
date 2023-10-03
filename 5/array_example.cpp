#include <array>
#include <string>

int main(int argc, char** argv)
{
    {
        std::array<int, 5> numbers;       // состоит из 5 чисел int
    }

    {
        std::array<int, 5> numbers {};    // состоит из 5 нулей
    }

    {
        std::array<int, 5> numbers {2, 3, 4, 5, 6};
    }

    {
        std::array<int, 5> numbers {2, 3, 4};     // {2, 3, 4, 0, 0}
    }

    //Начиная с c++17 можно так
    {
        std::array numbers {2, 3, 4, 5, 6};
    }

    //Основные методы
    {
        std::array<std::string, 3> people { "Tom", "Bob", "Sam" };
        std::string second = people.at(1);    // Bob
        std::string first = people.front();  // Tom
        std::string last = people.back();    // Sam

        people.fill("Undefined");  // people = { "Undefined", "Undefined", "Undefined" }
    }
    //На массивах определены операторы сравнения
    {
        std::array<std::string, 3> people1;
        std::array<std::string, 3> people2;

        bool is_equal = people1 <= people2;
    }
    return 0;
}