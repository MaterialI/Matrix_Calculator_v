#include <iostream>
#include<ctime>
#include<random>
#include "Matrix.h"
using namespace std;
int main()
{
	//more to be done
	/*Matrix a(2,2);
	a.fill();
	Matrix b(2, 2);
	b.fill();
	a.get_matrix();
	Matrix c = a * b;
	c.get_matrix();*/
	/*Matrix a(10, 10);
	a.get_matrix();
	cout << "________________________________" << endl;
	Matrix b = a;
	b.get_matrix();
	Matrix c = a * b;
	cout << "________________________________" << endl;
	c.get_matrix();*/
	int x = 3;
	int y = 3;
	float** arr1;
	arr1 = new float* [y];
	for (int i = 0; i < y; i++)
	{
		arr1[i] = new float[x];
		for (int j = 0; j < x; j++)
			arr1[i][j] = rand() % 101 - 50;
		
	}
	Matrix a(arr1, y, x);
	a.get_matrix();
	
	cout << "_________________________" << endl;
	float** arr2;
	arr2 = new float* [x];
	for (int i = 0; i < x; i++)
	{
		arr2[i] = new float[y];
		for (int j = 0; j < y; j++)
			arr2[i][j] = rand() % 101 -50;
	}
	Matrix b(arr2,x, y);
	b.get_matrix();
	cout << "_________________________" << endl;
	Matrix c = a.operator*(b);
	c.operator*(0.1);
	c.get_matrix();
}