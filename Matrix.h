#pragma once
class Matrix
{
public:
	Matrix();
	Matrix(int,int);
	//copy constructor 
	Matrix(const Matrix&);
	void operator =(const Matrix&);
	~Matrix();
	void fill();
	void get_matrix();
	void reset_size(int,int);
private:
	float** arr;
	int sizeX;
	int sizeY;
};

