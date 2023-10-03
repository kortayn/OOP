#include <queue>
#include <string>

//queue - обычная очередь
//priority_queue - приоритетная очередь, на вершине будет всегда более приоритетный элемент (по умолчанию наибольший)
int main(int argc, char** argv)
{
    std::queue<std::string> queue;  // пустая очередь
    
    bool is_empty = queue.empty();
    size_t size = queue.size();

    //Заполнение
    queue.push("Sam");
    queue.push("Tom");
    queue.push("Bob");
    

    //Получение элементов
    std::string first_element = queue.front(); //Для priority_queue будет Tom, а для queue будет Sam
    std::string last_element = queue.back();

    //Удаление
    queue.pop();
    return 0;
}