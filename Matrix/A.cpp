#include <iostream>
#include "Matrix.h"
using namespace std;
class A {
private:
    int rows, cols;
    int** arr;
public:
    A()
    {
        rows = cols = 0;
        arr = nullptr;
    }
    A(int rows, int cols)
    {
        this->rows = rows;
        this->cols = cols;
        arr = new int* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
    }
    A operator+(const A& b)
    {
        if (rows != b.rows || cols != b.cols)
            return *this;
        A rez(rows, cols);
        rez.arr = new int* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                rez.arr[i][j] = arr[i][j] + b.arr[i][j];
        }
    }
    A operator-(const A  & b)
    {
        if (rows != b.rows || cols != b.cols)
            return *this;
        A rez(rows, cols);
        rez.arr = new int* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                rez.arr[i][j] = arr[i][j] - b.arr[i][j];
        }
    }
    A operator/(const A& b)
    {
        if (rows != b.rows || cols != b.cols)
            return *this;
        A rez(rows, cols);
        rez.arr = new int* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if(b.arr[i][j]!=0)
                    rez.arr[i][j] = arr[i][j] / b.arr[i][j];
            }
        }
    }
    int* operator[](int index) {
        return arr[index];
    }
    A operator*(const A& b)
    {
        if (rows != b.rows || cols != b.cols)
            return *this;
        A rez(rows, cols);
        rez.arr = new int* [rows];
        for (int i = 0; i < rows; i++)
            arr[i] = new int[cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
                    rez.arr[i][j] = arr[i][j] * b.arr[i][j];
        }
    }
    A& operator = (int a)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                arr[i][j] = a;
            }
        }
        return *this;
    }
    friend ostream& operator<<(ostream& os, A& b);
};
ostream& operator<<(ostream& os, A& b)
{
    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.cols; j++)
        {
            os << b.arr[i][j] << ' ';
        }
        os << endl;
    }
    return os;
}
int main()
{
    srand(time(0));
    Matrix <A> arr_test(5, 5);
    arr_test.randInput();
    arr_test.print();
    Matrix <A> arr_test2(5, 5);
    arr_test2.randInput();
    arr_test2.print();
    Matrix <A> plus = arr_test + arr_test2;
    plus.print();
    Matrix <A> minus = arr_test - arr_test2;
    minus.print(); 
    Matrix <A> multi = arr_test * arr_test2;
    multi.print();
    Matrix <A> divide = arr_test / arr_test2;
    divide.print();

   /* arr_int.randInput();
    arr_double.randInput();
    arr_int.print();
    arr_double.print();*/
}
