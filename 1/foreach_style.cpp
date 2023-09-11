#include <iostream>
#include <memory>
int main(int argc, char** argv)
{
    int int_array[] {1,2,3,4,5};
    
    auto var = "askjdhasj";

    for(auto value : int_array)
    {
        std::cout << value << " ";
    }

    std::cout << std::endl;

    for(auto& ref_value : int_array){
        std::cout << ref_value << " ";
    }

    std::cout << std::endl;

    for(int value : int_array) //for(int i = 0; i < 5; ++i)
    {                           //int value = int_array[i];
        std::cout << value << " ";
    }

    std::cout << std::endl;

    for(int& ref_value : int_array){
        std::cout << ref_value << " ";
    }
    return 0;
}