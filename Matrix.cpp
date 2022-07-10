#include "Matrix.h"
#include <iostream>
using namespace std;
//default constructor with redundant features
Matrix::Matrix()
{
	sizeX = 1;
	sizeY = 1;
	arr = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = 0;
	}
}
//overloaded constructor
Matrix::Matrix(int sizeY, int sizeX)
{
	this->sizeY = sizeY;
	this->sizeX = sizeX;
	arr = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = 0;
	}
}
//copy constructor
Matrix::Matrix(const Matrix& other)
{
	sizeX = other.sizeX;
	sizeY = other.sizeY;
	arr = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = other.arr[i][j];
	}
}
//assignment operator
void Matrix::operator= (const Matrix& other)
{
	if (sizeX != other.sizeX || sizeY != other.sizeY)
	{
		sizeX = other.sizeX;
		sizeY = other.sizeY;
		delete arr;
		arr = new float* [sizeY];
		for (int i = 0; i < sizeY; i++)
		{
			arr[i] = new float[sizeX];
			for (int j = 0; j < sizeX; j++)
				arr[i][j] = other.arr[i][j];
		}
	}
	else
	{
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
				arr[i][j] = other.arr[i][j];
		}
	}
}
//destructor
Matrix::~Matrix()
{
	delete arr;
}
//flii matrix with numbers
void Matrix::fill()
{
	float tmp;
	cout << "Please, enter your matrix sequentially: ";
	for (int i = 0; i < sizeY; i++)
	{
		cout << "Enter " << i << " row:";
		for (int j = 0; j < sizeX; j++)
		{
			cout << "Enter " << j << " entry: ";
			cin >> tmp;
			arr[i][j] = tmp;
		}
	}
}
//and also this
void Matrix::get_matrix()
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}
//be careful  (empties matrix), soon complementing and merging will be added. 
void Matrix::reset_size(int n_sizeY, int n_sizeX)
{
	if (sizeX != n_sizeX || sizeY != n_sizeY)
	{
		delete arr;
		sizeX = n_sizeX;
		sizeY = n_sizeY;
		arr = new float* [sizeY];
		for (int i = 0; i < sizeY; i++)
		{
			arr[i] = new float[sizeX];
			for (int j = 0; j < sizeX; j++)
				arr[i][j] = 0;
		}
	}
}