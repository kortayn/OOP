#include <ctype.h>
#include <string>

class MyInteger
{
public:
    MyInteger()
    {
        value = std_value;
    }

    MyInteger(int val)
    {
        value = val;
    }

    static MyInteger parse(std::string input)
    {
        int result = 0;
        for(auto& character : input)
        {
            if(isdigit(character) == true)
            {
                result *= 10;
                result += character - '0';
            }
        }
        MyInteger my_integer(result);
        return my_integer;
    }

private:
    static const int std_value = 0;
    int value;
};

int main(int argc, char** argv)
{
    return 0;
}