#pragma once
#include<iostream>
#include<iomanip>
using namespace std;

template<class T>
class Matrix
{
	T** arr;
	int rows;
	int cols;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix<T>& a);
	~Matrix();
	void randInput();
	void print();
	Matrix<T> operator+(const Matrix<T> &b);
	Matrix<T> operator-(const Matrix<T> &b);
	Matrix<T> operator/(const Matrix<T> &b);
	Matrix<T> operator*(const Matrix<T> &b);
};
template <class T>
Matrix<T>::Matrix()
{
	rows = cols = 0;
	arr = nullptr;
}
template <class T>
Matrix<T>::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;
	arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
}
template <class T>
Matrix<T>::Matrix(const Matrix<T>& b)
{
	rows = b.rows;
	cols = b.cols;
	arr = new T * [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = b.arr[i][j];
		}
	}
}
template <class T>
Matrix<T>::~Matrix()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[]arr;
}
template <class T>
void Matrix<T>::randInput()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = rand() % 101;
		}
	}
}
template <class T>
void Matrix<T>::print()
{
	for (size_t i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout <<arr[i][j]<< ' ';
		}
		cout << endl;
	}
	cout << endl;
}
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &b)
{
	if (b.rows != rows || b.cols != cols)
		return *this;
	Matrix<T> rez(rows,cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			rez.arr[i][j] = arr[i][j] + b.arr[i][j];
	}
	return rez;
}
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &b)
{
	if (b.rows != rows || b.cols != cols)
		return *this;
	Matrix<T> rez(rows,cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			rez.arr[i][j] = arr[i][j]-b.arr[i][j];
	}
	return rez;
}
template <class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T> &b)
{
	if (b.rows != rows || b.cols != cols)
		return *this;
	Matrix<T> rez(*this);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (b.arr[i][j] != 0)
				rez.arr[i][j] = arr[i][j] / b.arr[i][j];
		}

	}
	return rez;
}
template <class T>
Matrix<T> Matrix<T>:: operator*(const Matrix<T>& b)
{
	if (b.rows != rows || b.cols != cols)
		return *this;
	Matrix<T> rez(*this);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
				rez.arr[i][j] = arr[i][j] * b.arr[i][j];

	}
	return rez;
}
