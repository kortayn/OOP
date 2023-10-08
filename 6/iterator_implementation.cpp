#include <algorithm>
#include <iterator>
#include <cstddef>
#include <iostream>

/*
1 Input Iterator. Может просканировать контейнер вперед только один раз, не может изменить значение, на которое он указывает (только для чтения);
2 Output Iterator. Может просканировать контейнер вперед только один раз, не может читать значение, на которое он указывает (только запись);
3 Forward Iterator. Может многократно просканировать контейнер вперед, может читать и записывать значение, на которое он указывает;
4 Bidirectional Iterator. То же, что и предыдущий, но может сканировать контейнер вперед и назад;
5 Random Access Iterator. То же, что и предыдущий, но может обращаться к контейнеру и непоследовательно (т.е. перескакивая);
6 Contiguous Iterator. То же, что и предыдущий, с добавлением того, что логически смежные элементы являются и физически смежными в памяти.

Полную информацию по итераторам можно найти тут https://en.cppreference.com/w/cpp/iterator
Тут https://cplusplus.com/reference/iterator/ табличка с операциями, которые должны быть реализованы для итераторов определённых типов.
*/

class Integers
{
public:
    struct Iterator 
    {
        //C++ ожидает от итераторов наличия некоторых свойств, в C++20 испольхуются концепты
        //до этого стандарта использовался механизм диспетчеризации тегов
        //Список тегов итераторов можно посмотреть тут https://en.cppreference.com/w/cpp/iterator/iterator_tags:

        //категория создаваемого итератора
        using iterator_category = std::forward_iterator_tag;
        
        //знаковый целочисленный тип, который может быть использован
        //для определения расстояния между шагами итератора.
        //В нашем случае указатель подоёдёт т.к. итератор по сути является обёрткой над указателем
        using difference_type   = std::ptrdiff_t;
        
        //тип значений в коллекции
        using value_type        = int;

        //тип над которым выполняется итерация
        using pointer           = int*;

        //Ссылка на итерируемый тип
        using reference         = int&;

        Iterator(pointer ptr) : m_ptr(ptr) {}

        reference operator*() const { return *m_ptr; }
        pointer operator->() { return m_ptr; }
        Iterator& operator++() { m_ptr++; return *this; }  
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        
        friend bool operator== (const Iterator& a, const Iterator& b)
        {
            return a.m_ptr == b.m_ptr;
        };
        
        friend bool operator!= (const Iterator& a, const Iterator& b)
        {
            return a.m_ptr != b.m_ptr;
        };  

    private:
        pointer m_ptr;
    };

    Iterator begin() { return Iterator(&m_data[0]); }
    Iterator end()   { return Iterator(&m_data[200]); }

private:
    int m_data[200];
};

int main(int argc, char** argv)
{
    Integers integers;

    std::fill(integers.begin(), integers.end(), 10);    
    
    for (int i : integers)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    for (Integers::Iterator it = integers.begin(), end = integers.end(); it != end; ++it) { 
        const int i = *it; 
        std::cout << i << " ";
    }
    
    return 0;
}