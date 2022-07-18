#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int,int);
	//copy constructor 
	Matrix(const Matrix&);
	Matrix& operator =(const Matrix&);
	~Matrix();
	void fill();
	void get_matrix() const;
	Matrix operator + (const Matrix&);
	Matrix operator -(const Matrix&);
	Matrix operator *(const Matrix&);
private:
	float** arr;
	int sizeX;
	int sizeY;
	void reset_size(int, int);
};

