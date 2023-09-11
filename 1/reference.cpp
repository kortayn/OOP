int main(int argc, char** argv)
{
    int value = 5;
    int& int_ref{value};

    int& int_ref2; //так нельзя!
    int& int_ref3 = 10; //так тоже!

    //константные ссылки
    const int value2 = 15;
    const int& int_ref4 = value2;
}