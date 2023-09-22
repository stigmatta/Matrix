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
};
int main()
{
    srand(time(0));
    Matrix <A> arr(5, 5);
    arr.print();
    Matrix<double> test(5, 5);
    arr.randInput();
    test.randInput();
    arr.print();
    test.print();
}
