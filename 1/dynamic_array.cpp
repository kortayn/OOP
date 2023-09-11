int main(int argc, char **argv){
    //создание
    int *int_array1 {new int[4]};
    int *int_array2 = new int[4];

    //инициализация
    int *int_array3 {new int[4]{}}; //0,0,0,0
    int *int_array4 {new int[4]{1,2,3,4}}; //1,2,3,4
    int *int_array5 {new int[4]{1,2}}; //Что будет тут?

    //Для с++20 можно так int *int_array6 {new int[]{1,2,3,4}};
    //Доступ к элементам int_array4[i] или *(int_array4 + i)

    //Удаление
    int *int_array6 {new int[4]{1,2,3,4}};
    delete[] int_array6;
    int_array6 = nullptr;
   

    //Многомерные массивы
    unsigned rows = 3;       
    unsigned columns = 2;    
    int** int_array2d{new int*[rows]{}}; 
    
    for (unsigned i{}; i < rows; i++)
    {
        int_array2d[i] = new int[columns]{};
    }
 
    for (unsigned i{}; i < rows; i++)
    {
        delete[] int_array2d[i];
    }
    delete[] int_array2d;

    //Разреженные массивы
    int** int_sparse_array2d {new int*[5]};
    int_sparse_array2d[0] = new int[10];
    int_sparse_array2d[0][0] = 9;
    int_sparse_array2d[1] = new int[14];
    int_sparse_array2d[1][0] = 14;
    int_sparse_array2d[2] = new int[2];
    int_sparse_array2d[2][0] = 1;
    int_sparse_array2d[3] = new int[9];
    int_sparse_array2d[3][0] = 8;
    int_sparse_array2d[4] = new int[100];
    int_sparse_array2d[4][0] = 99;
     
    return 0;
 }