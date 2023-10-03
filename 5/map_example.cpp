#include <map>
#include <string>

int main(int argc, char** argv)
{
    {
        std::map<std::string, unsigned> products;
    // установка значений
        products["bread"] = 30;
        products["milk"] = 80;
        products["apple"] = 60;
    }

    //Инициалиация
    {
        {
            std::map<std::string, unsigned> products
            {
                std::pair<std::string, unsigned>{"bread", 30},
                std::pair<std::string, unsigned>{"milk", 80},
                std::pair<std::string, unsigned>{"apple", 60}
            };
        }

        {
            std::map<std::string, unsigned> products
            {
                {"bread", 30},
                {"milk", 80},
                {"apple", 60}
            };
        }        
    }

    //Удаление, определение количества элементов
    //и нахождение элемента как в set
    
    return 0;
}