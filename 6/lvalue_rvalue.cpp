#include <string>
#include <utility>
#include <iostream>

std::string return_string()
{
    std::string str{"Random string"};
    return str;
}

int main(int argc, char** argv)
{
    float var = 10.0f; //var - lvalue, 10.0f - rvalue
    
    float&& rv_ref {var + 5.0f}; //rv_ref - ссылка на rvalue
    
    // float&& rv_ref2 = var; //так нельзя rv_ref2 - rvalue

    float&& rv_ref2 = std::move(var); // так можно. move преобразует тип в rvalue

    //тут применится оптимизация и переменная str внутри return_string не будет создаваться
    //из-за того, что str - rvalue
    std::string ret_str = return_string(); 

    return 0;
}