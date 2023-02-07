
#include "Matrix.h"
//#include <dvec.h>
#include <iostream>
using namespace std;
//default constructor with redundant features
//description: populates the matrix of size 1x1 with value 0

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
//description: creates square matrix based on size argument
//postcondition: identity matrix is created
Matrix::Matrix(int size)
{
	sizeX = size;
	sizeY = size;
	arr = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for(int j = 0;j<sizeX;j++)
		{
			if (i == j)
			{
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = 0;
		}
	}
}

//overloaded constructor
//description: creates any matrix including vectors based on the arguments of size x and y. 
//postcondition: matrix/vector created and populated with 0s
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
//description: instantiates a copy of given matrix
//postcondition: the matrix instance is created
Matrix::Matrix(const Matrix& other)
{
	sizeX = other.sizeX;
	sizeY = other.sizeY;
	arr = new float* [sizeY]; //operator* doesnt pass matrix tp other;
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = other.arr[i][j];
	}
}

//overloaded constructor 
//description: instantiates an instance of a matrix based on a 2-dimentional 
// float** array and size x and y of the array
//postcondition: 
Matrix::Matrix(float** p_arr, int sizeY, int sizeX)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	arr = new float* [sizeY];
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = p_arr[i][j];
	}
}
//assignment operator
Matrix& Matrix::operator= (const Matrix& other)
{
	sizeX = other.sizeX;
	sizeY = other.sizeY;
	if (sizeX != other.sizeX || sizeY != other.sizeY)
	{

		delete[] arr;
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
	return *this;
}
//destructor
Matrix::~Matrix()
{
	delete[] arr;
}
//public method
//fills the matrix with numbers row-wise
//postcondition: the matrix is filled with numbers
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
//public method
//prints out matrix to the user
void Matrix::get_matrix() const
{
	for (int i = 0; i < sizeY; i++)
	{
		for (int j = 0; j < sizeX; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}
//be careful  (empties matrix), soon complementing and merging will be added. 
//Private method 
//resizes the matrix to specific dimentions 
// postcondition: the matrix is resized, but EMPTY!!!!
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
/////operations
//Addition operator
//adds entries of another matrix if both of them match their dimentions
//postcondition: matrix has recalculated entries
Matrix Matrix::operator+(const Matrix& other)
{
	Matrix nm(*this);
	if (sizeY == other.sizeY && sizeX == other.sizeX)
	{
		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
				nm.arr[i][j] += other.arr[i][j];
		}
	}
	else
		cout << "Addition can't be performed: different dimensions" << endl;
	return nm;
}
//Addition operator
//substracts entries of another matrix if both of them match their dimentions
//postcondition: the matrix has recalculated entries 
Matrix Matrix::operator-(const Matrix& other)
{
	Matrix nm(*this);
	if (sizeY == other.sizeY && sizeX == other.sizeX)
	{

		for (int i = 0; i < sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
				nm.arr[i][j] -= other.arr[i][j];
		}
	}
	else
		cout << "Substraction can't be performed: different dimensions" << endl;
	return nm;
}
//multiplication operator
//multiplies two matricies if both of them match their dimentions
//postcondition: the matrix has recalculated entries 
Matrix Matrix::operator*(const Matrix& other)
{
	if (sizeX == other.sizeY/* && sizeX == sizeY*/)
	{
		Matrix res(sizeY, other.sizeX);
		for (int i = 0; i < sizeX * sizeY; i++)
		{
			for (int j = 0; j < sizeX; j++)
			{

				res.arr[(i - (i % sizeX)) / sizeX][i % sizeX] +=
					arr[((i - (i % sizeX)) / sizeX)][j] * other.arr[j][(i % sizeX)];
			}
		}
		return res;
	}
	else
		cout << "Multiplication cannot be performed, \n please verify that you entered correct dimentions for matricies" << endl;
}
//scalar operator
//scale entries the matrix 
//postcondition: the matrix has recalculated entries 
Matrix Matrix::operator* (float cf)
{
	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeY; j++)
			arr[i][j] *= cf;
	return *this;
}
void Matrix::rrefRow()
{
	int current = 0;
	if (sizeY != 1 && sizeY != 1)
		rrefRowR(current);
	else
		cout << "Cannot Be row reduced (size < 1)" << endl;
}
void Matrix::rrefRowR(int current)
{
	if (current == sizeY || current == sizeX)
	{
		return;
	}
	else
	{
		for (int i = current+1; i < sizeY && i < sizeX; i++)
		{
			rowReduceS(i, current);
		}
		rrefRowR(current + 1);
		for (int i = current-1; i >= 0; i--)
		{
			rowReduceS(i, current);
		}
	}
}

//Description: difference = difference - substracted i.e. the leading number in the row of [difference] will be 0
void Matrix::rowReduceS(int difference, int substracted)
{
	if (this->arr[difference][substracted] == 0)
	{
		return;
	}
	float coeff = this->arr[substracted][substracted];
	for (int i = 0; i < this->sizeX; i++)	// normalize vector
	{
		this->arr[substracted][i] = this->arr[substracted][i] / coeff;
	}	
	coeff = this->arr[difference][substracted];
	for (int i = 0; i < this->sizeX; i++)	// perform the substraction
	{
		this->arr[difference][i] -= this->arr[substracted][i] * coeff;
	}
	return;
}

//recursive private method. Creates row-reduced matrix
//is used for inverse

void Matrix::rowReduceInverse(Matrix& identity, int difference, int substracted)
{
	if (this->arr[difference][substracted] == 0)
	{
		return;
	}
	float coeff = this->arr[substracted][substracted];
	for (int i = 0; i < this->sizeX; i++)	// normalize vector
	{
		this->arr[substracted][i] = this->arr[substracted][i] / coeff;
		identity.arr[substracted][i] /= coeff;
	}
	coeff = this->arr[difference][substracted];
	for (int i = 0; i < this->sizeX; i++)	// perform the substraction
	{
		this->arr[difference][i] -= this->arr[substracted][i] * coeff;
		identity.arr[difference][i] -= identity.arr[substracted][i] * coeff;
	}
	return;
}

//wrapper function for inverse
//precondition: the matrix is square
//postcondition: the matrix is inversed
void Matrix::inverse()
{
	Matrix identity(this->sizeX);
	if (this->sizeX != this->sizeY && sizeX>1)
	{
		cout << "the inverse cannot be done: the matrix is not square" << endl;
		return;
	}
	else
	{
		int current = 0;
		inverseR(identity, current);
	}
}

//recursive private method
//generates inverse through row-reduction of the function
void Matrix::inverseR(Matrix& identity, int current)
{
	if (current == sizeY || current == sizeX)
	{
		return;
	}
	else
	{
		for (int i = current + 1; i < sizeY && i < sizeX; i++)
		{
			rowReduceInverse(identity, i, current);
		}
		inverseR(identity, current + 1);
		for (int i = current - 1; i >= 0; i--)
		{
			rowReduceInverse(identity, i, current);
		}
	}
}