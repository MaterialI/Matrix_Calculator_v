//#include "Matrix.h"
//#include <iostream>
//using namespace std;
////default constructor with redundant features
//Matrix::Matrix()
//{
//	sizeX = 1;								
//	sizeY = 1;								
//	arr = new float* [sizeY];		
//	for (int i = 0; i < sizeY; i++)
//	{
//		arr[i] = new float[sizeX];
//		for (int j = 0; j < sizeX; j++)
//			arr[i][j] = 0;
//	}
//}
//Matrix::Matrix(int size)
//{
//	sizeX = sizeY = size;
//	arr = new float* [size];
//	for(int i = 0; i<size; i++)
//	{
//		arr[i] = new float[size];
//		for(int j= 0;j<size;j++)
//		{
//			if(i == j)
//			{
//				arr[i][j] = 1;
//			}
//			else arr[i][j] = 0;
//		}
//	}
//}
////overloaded constructor
//Matrix::Matrix(int sizeY, int sizeX)
//{
//	this->sizeY = sizeY;
//	this->sizeX = sizeX;
//	arr = new float* [sizeY];
//	for (int i = 0; i < sizeY; i++)
//	{
//		arr[i] = new float[sizeX];
//		for (int j = 0; j < sizeX; j++)
//			arr[i][j] = 0;
//	}
//}
////copy constructor
//Matrix::Matrix(const Matrix& other)
//{
//	sizeX = other.sizeX;
//	sizeY = other.sizeY;
//	arr = new float* [sizeY]; //operator* doesnt pass matrix tp other;
//	for (int i = 0; i < sizeY; i++)
//	{
//		arr[i] = new float[sizeX];
//		for (int j = 0; j < sizeX; j++)
//			arr[i][j] = other.arr[i][j];
//	}
//}
//Matrix::Matrix(float** p_arr, int sizeY, int sizeX)
//{
//	this->sizeX = sizeX;
//	this->sizeY = sizeY;
//	arr = new float* [sizeY];
//	for (int i = 0; i < sizeY; i++)
//	{
//		arr[i] = new float[sizeX];
//		for (int j = 0; j < sizeX; j++)
//			arr[i][j] = p_arr[i][j];
//	}
//}
////assignment operator
//Matrix& Matrix::operator= (const Matrix& other)
//{
//	sizeX = other.sizeX;
//	sizeY = other.sizeY;
//	if (sizeX != other.sizeX || sizeY != other.sizeY)
//	{
//		
//		delete[] arr;
//		arr = new float* [sizeY];
//		for (int i = 0; i < sizeY; i++)
//		{
//			arr[i] = new float[sizeX];
//			for (int j = 0; j < sizeX; j++)
//				arr[i][j] = other.arr[i][j];
//		}
//	}
//	else
//	{
//		for (int i = 0; i < sizeY; i++)
//		{
//			for (int j = 0; j < sizeX; j++)
//				arr[i][j] = other.arr[i][j];
//		}
//	}
//	return *this;
//}
////destructor
//Matrix::~Matrix()
//{
//	delete[] arr;
//}
////fill matrix with numbers
//void Matrix::fill()
//{
//	float tmp;
//	cout << "Please, enter your matrix sequentially: ";
//	for (int i = 0; i < sizeY; i++)
//	{
//		cout << "Enter " << i << " row:";
//		for (int j = 0; j < sizeX; j++)
//		{
//			cout << "Enter " << j << " entry: ";
//			cin >> tmp;
//			arr[i][j] = tmp;
//		}
//	}
//}
////and also this
//void Matrix::get_matrix() const
//{
//	for (int i = 0; i < sizeY; i++)
//	{
//		cout << "[ ";
//		for (int j = 0; j < sizeX; j++)
//			cout << arr[i][j] << " ";
//		
//		cout <<" ]" << '\n';
//	}
//}
////be careful  (empties matrix), soon complementing and merging will be added. 
//void Matrix::reset_size(int n_sizeY, int n_sizeX)
//{
//	if (sizeX != n_sizeX || sizeY != n_sizeY)
//	{
//		delete arr;
//		sizeX = n_sizeX;
//		sizeY = n_sizeY;
//		arr = new float* [sizeY];
//		for (int i = 0; i < sizeY; i++)
//		{
//			arr[i] = new float[sizeX];
//			for (int j = 0; j < sizeX; j++)
//				arr[i][j] = 0;
//		}
//	}
//}
///////operations
//Matrix Matrix::operator+(const Matrix& other)
//{
//	Matrix nm(*this);
//	if (sizeY == other.sizeY && sizeX == other.sizeX)
//	{
//		for (int i = 0; i < sizeY; i++)
//		{
//			for (int j = 0; j < sizeX; j++)
//				nm.arr[i][j] += other.arr[i][j];
//		}
//	}
//	else
//		cout << "Addition can't be performed: different dimensions"<<endl;
//	return nm;
//}
//Matrix Matrix::operator-(const Matrix& other)
//{
//	Matrix nm(*this);
//	if (sizeY == other.sizeY && sizeX == other.sizeX)
//	{
//		
//		for (int i = 0; i < sizeY; i++)
//		{
//			for (int j = 0; j < sizeX; j++)
//				nm.arr[i][j] -= other.arr[i][j];
//		}
//	}
//	else
//		cout << "Substraction can't be performed: different dimensions" << endl;
//	return nm;
//}
//Matrix Matrix::operator*(const Matrix& other) 
//{
//	if (sizeX == other.sizeY/* && sizeX == sizeY*/)
//	{
//
//		//if(size)
//		Matrix res(sizeY, other.sizeX);
//			for (int i = 0; i < other.sizeX * sizeY; i++)
//			{
//				for (int j = 0; j < sizeX; j++)
//				{
//
//					res.arr[(i - (i % other.sizeX)) / other.sizeX][i % other.sizeX] +=
//						arr[((i - (i % other.sizeX)) / other.sizeX)][j] * other.arr[j][(i % other.sizeX)];
//				}
//			}
//		return res;
//	}
//	else
//		cout << "Multiplication cannot be performed, \n please verify that you entered correct dimentions for matricies" << endl;
//}
//Matrix Matrix::operator* (float cf)
//{
//	for (int i = 0; i < sizeY; i++)
//		for (int j = 0; j < sizeY; j++)
//			arr[i][j] *= cf;
//	return *this;
//}
//bool Matrix::operator==(const Matrix& other) const
//{
//	bool equal = true; 
//	if(this->sizeX!= other.sizeX|| this->sizeY!= other.sizeY)
//	{
//		return false;
//	}
//	for(int i = 0 ; i< sizeY;i++)
//	{}
//}
//Matrix Matrix::invese()
//{
//	Matrix id(this->sizeX);
//	Matrix id_ref(sizeX);
//	
//}
//Matrix& rec_inv(Matrix& other, Matrix& id, const Matrix& id_ref)
//{
//	if(id_ref == other)
//		return other;
//	else
//	{
//		
//	}
//}
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
	arr = new float* [sizeY]; //operator* doesnt pass matrix tp other;
	for (int i = 0; i < sizeY; i++)
	{
		arr[i] = new float[sizeX];
		for (int j = 0; j < sizeX; j++)
			arr[i][j] = other.arr[i][j];
	}
}
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
//fill matrix with numbers
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

void Matrix::inverse(Matrix& identity)
{
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