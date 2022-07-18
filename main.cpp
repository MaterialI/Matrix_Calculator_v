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
	float** arr;
	arr = new float* [3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new float[3];
		for (int j = 0; j < 3; j++)
			arr[i][j] = rand() % 100 + 1;
		
	}
	Matrix a(arr, 3, 3);
	a.get_matrix();
	cout << "_________________________" << endl;
	Matrix b(arr,3, 3);
	cout << "_________________________" << endl;
	a.operator*(b).get_matrix();
	
	
}