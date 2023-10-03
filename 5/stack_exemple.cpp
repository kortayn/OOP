#include <stack>
#include <string>

int main(int argc, char** argv)
{
    std::stack<std::string> stack;    // пустой стек строк
    bool is_empty = stack.empty();
    size_t size = stack.size();

    stack.push("Tom");
    stack.push("Bob");
    stack.push("Sam");

    std::string top_element = stack.top(); // Sam
    stack.pop();    // извлекаем верхний элемент

    return 0;
}