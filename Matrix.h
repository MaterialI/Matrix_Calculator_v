// #pragma once
// class Matrix
// {
// public:
// 	Matrix();
// 	Matrix(int,int);
// 	//copy constructor 
// 	Matrix(const Matrix&);
// 	Matrix(float**, int, int);
// 	Matrix& operator =(const Matrix&);
// 	bool operator ==(const Matrix&) const;
// 	~Matrix();
// 	void fill();
// 	void get_matrix() const;
// 	Matrix operator + (const Matrix&);
// 	Matrix operator - (const Matrix&);
// 	Matrix operator * (const Matrix&);
// 	Matrix operator*(float);
// 	Matrix invese();

// private:
// 	Matrix(int);
// 	friend Matrix& rec_inv(Matrix&, Matrix&, const Matrix&);
// 	float** arr;
// 	int sizeX;
// 	int sizeY;
// 	void reset_size(int, int);
// };

//#include "MatrixInverse.h"
using namespace std;
class Matrix
{
public:
	Matrix();
	Matrix(int);
	Matrix(int,int);
	//copy constructor 
	Matrix(const Matrix&);
	Matrix(float**, int, int);
	Matrix& operator =(const Matrix&);
	~Matrix();
	void fill();
	void get_matrix() const;
	Matrix operator + (const Matrix&);
	Matrix operator - (const Matrix&);
	Matrix operator * (const Matrix&);
	Matrix operator * (float);
	void rrefRow(); 
	void inverse(Matrix& identity);
private:	
	void rrefRowR(int curr);
	void rowReduceS(int decreased, int substracted);
	void rowReduceInverse(Matrix& identity, int decreased, int substracted);
	
	void inverseR(Matrix& identity, int curr);
	//MatrixInverse inverse();
	float** arr;
	int sizeX;
	int sizeY;
	void reset_size(int, int);
};


